#include <iostream>
#include <vector>

#include "direct_input.hpp"
#include "direct_input_keyboard.hpp"
#include "errors.hpp"
#include "keys.hpp"
#include "settings.hpp"

const std::string usage {
"Usage: <check keyboard timeout> <clean clipboard timeout> [ <key name> ... ]\n"
"   <check keyboard timeout>    timeout between reading keyboard buttons state\n"
"                               in miliseconds\n"
"   <clean clipboard timeout>   clean cliboard timeout after detecting keyboard\n"
"                               keys combination\n"
"   <key name>                  key name from list:\n"
};

void printUsage() {
    std::cout << usage;
    std::vector<std::string> keyNames;
    std::transform(keys.begin(), keys.end(), std::back_inserter(keyNames),
        [] (const std::pair<std::string, Key> &key) { return key.first; });
    std::sort(keyNames.begin(), keyNames.end());
    for (const auto &keyName : keyNames) {
        std::cout << "        " << keyName << std::endl;
    }
}

using Handle = std::function<void (const DirectInputKeyboardState &)>;

void globalKeyboardHook(HINSTANCE instance, Handle handle,
        const unsigned timeout) {
    DirectInput input(instance);
    auto device = input.createKeyboard();
    while (true) {
        handle(device.getState());
        Sleep(timeout);
    }
}

void cleanClipboard() {
    if (!OpenClipboard(nullptr)) {
        throw OpenClipboardError(GetLastError());
    }

    if (!EmptyClipboard()) {
        throw EmptyClipboardError(GetLastError());
    }

    CloseClipboard();
}

void cleanClipboardRepeat(const unsigned maxTriesCount = 10,
        const unsigned timeout = 1) {
    bool isClean = false;

    for (unsigned tryNum = 1; !isClean; ++tryNum) {
        try {
            cleanClipboard();
            isClean = true;
        } catch (const ClipboardError &error) {
            if (tryNum > maxTriesCount) {
                throw error;
            }
            std::cerr << "#" << tryNum << " try " << error.what() << std::endl;
            Sleep(timeout);
        }
    }
}

void runCleanCliboard(HINSTANCE instance, const unsigned checkKeyboardTimeout,
        const unsigned cleanTimeout, const std::vector<Key> &keysCombination) {
    globalKeyboardHook(instance, [&keysCombination, cleanTimeout]
        (const  DirectInputKeyboardState &state) {
            if (state.isKeysDown(keysCombination)) {
                Sleep(cleanTimeout);
                try {
                    cleanClipboardRepeat();
                } catch (const ClipboardError &error) {
                    std::cerr << error.what() << std::endl;
                }
            }
        }, checkKeyboardTimeout);
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR cmd, int) {
    try {
        const auto settings = parseSettings(cmd);
        runCleanCliboard(instance, settings.checkKeyboardTimeout,
            settings.cleanTimeout, settings.keysCombination);
        return 0;
    } catch (const ParseSettingsError &error) {
        std::cerr << error.what() << std::endl;
        printUsage();
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    } catch (...) {
        std::cerr << "unknown error" << std::endl;
    }
    return 1;
}

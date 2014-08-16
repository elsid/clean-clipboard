set(EXECUTABLE_OUTPUT_PATH ../bin)

set(SOURCES
    direct_input.cpp
    direct_input_keyboard.cpp
    keys.cpp
    main.cpp
    settings.cpp
)

add_executable(clean-clipboard ${SOURCES})

target_link_libraries(clean-clipboard
    dinput8
    dxguid
)

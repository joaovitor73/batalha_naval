# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

add_compile_definitions(PICO_SUPPORT_SMP=1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.1)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.1.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(main C CXX ASM)

# Pull in FreeRTOS
include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)


# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(main main.c neo/src/neopixel.c display/src/display.c  display/inc/ssd1306_i2c.c
buzzer/src/buzzer.c joystick/src/joystick.c button/src/button.c rede/mqtt/src/mqtt.c rede/wifi/src/wifi.c led/src/led.c)

pico_set_program_name(main "main")
pico_set_program_version(main "0.1")


# Add the standard library to the build
target_link_libraries(main
        pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)

pico_generate_pio_header(main ${CMAKE_CURRENT_LIST_DIR}/neo/pio_neopixel/ws2818b.pio)

# Add the standard library to the build
target_link_libraries(main
        pico_stdlib)

pico_enable_stdio_usb(main 1)

# Add the standard include files to the build
target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/generated
)

# Add any user requested libraries
target_link_libraries(main 
        hardware_pio
        hardware_clocks
        hardware_i2c
        hardware_pwm
        hardware_adc
        pico_stdlib
        pico_cyw43_arch_lwip_threadsafe_background
        pico_lwip_mqtt
        pico_lwip
        pico_cyw43_driver
     )

pico_add_extra_outputs(main)


cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME ard_1)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_BOARD diecimila)
set(${CMAKE_PROJECT_NAME}_PORT /dev/cu.usbserial-A6008jd1)
set(${CMAKE_PROJECT_NAME}_SKETCH morse.ino)

set(diecimila.build.mcu atmega328p)
set(diecimila.upload.protocol arduino)
set(diecimila.upload.speed 57600)

generate_arduino_firmware(${CMAKE_PROJECT_NAME})

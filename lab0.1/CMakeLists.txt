﻿# CMakeList.txt: проект CMake для OOP_with_CMake; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("OOP_with_CMake")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (OOP_with_CMake "main.cpp" "address.h" "address.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

cmake_minimum_required(VERSION 3.10)

# Название проекта
project(My_nums_project)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка путей для заголовочных файлов и исходных файлов
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Указание компилятору, где искать заголовочные файлы
include_directories(${INCLUDE_DIR})

# Автоматический поиск всех .cpp файлов в папке src
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

# Создание библиотеки из исходников
add_library(My_nums_lib ${SOURCES})

# Создание исполняемого файла для основной программы
add_executable(My_nums_exe main.cpp)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(My_nums_exe PRIVATE My_nums_lib)

# ===================== Google Test ===================== #

# Подключение GoogleTest через FetchContent
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)

# Скачать и сделать доступным GoogleTest
FetchContent_MakeAvailable(googletest)

# Включаем поддержку тестов
enable_testing()

# Добавление тестов
add_executable(My_nums_tests tests.cpp)

# Линковка библиотеки и Google Test с тестами
target_link_libraries(My_nums_tests gtest gtest_main My_nums_lib)

# Добавление тестов для запуска через CTest
add_test(NAME My_nums_tests COMMAND My_nums_tests)


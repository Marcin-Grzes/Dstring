cmake_minimum_required(VERSION 3.28)
project(Dstring2)

set(CMAKE_CXX_STANDARD 17)

# Dodajemy katalog zawierający pliki nagłówkowe GoogleTest
include_directories(/opt/homebrew/opt/googletest/include)

# Dodajemy bibliotekę GoogleTest
link_directories(/opt/homebrew/opt/googletest/lib)

add_executable(Dstring2
        DString.cpp
        TestMain.cpp)

# Dodajemy plik z testami
add_executable(runTests
        DString.cpp
        tests.cpp)

# Linkujemy GoogleTest z projektem testów
target_link_libraries(runTests gtest gtest_main)
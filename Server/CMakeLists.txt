cmake_minimum_required(VERSION 3.16)

project(viavlo_server)

# Menggunakan Standar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Mencari semua file .cpp dan .h di dalam folder src
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/*.h"
)

# Menambahkan executable
add_executable(server ${SOURCES})

# Memberitahu CMake bahwa header (.h) sekarang ada di dalam folder src
target_include_directories(server PRIVATE src)

cmake_minimum_required(VERSION 3.10)
project(musl-parts C ASM)

add_definitions(
    -D_WSLTUB
    -D_XOPEN_SOURCE=700
)

# -Os 
# -pipe 
add_compile_options(
    -std=c99
    -ffreestanding
    -nostdinc

    -Wno-logical-op-parentheses
    -Wno-unused-command-line-argument
    -Wno-shift-op-parentheses
    -Wno-string-plus-int
    -Wno-ignored-attributes
    -Wno-bitwise-op-parentheses
    -Wno-parentheses
    -fPIC

    -fomit-frame-pointer 
    -fno-unwind-tables 
    -fno-asynchronous-unwind-tables 
    -ffunction-sections 
    -fdata-sections 
    -Werror=implicit-function-declaration 
    -Werror=implicit-int 
    -Werror=pointer-sign 
    -Werror=pointer-arith  
    -Wl,--sort-section,alignment 
    -Wl,--sort-common 
    -Wl,--gc-sections 
    -Wl,--hash-style=both 
    -Wl,--no-undefined 
    -Wl,--exclude-libs=ALL 
    -Wl,--dynamic-list=./dynamic.list  
    -nostdlib 
    -shared
)
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/arch/x86_64"
    "${CMAKE_CURRENT_SOURCE_DIR}/arch/generic"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/internal"
    "${CMAKE_CURRENT_SOURCE_DIR}/obj/src/internal"
    "${CMAKE_CURRENT_SOURCE_DIR}/obj/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_subdirectory(src)
add_library(musl-parts SHARED dummy.c)
target_link_libraries(musl-parts
    -Wl,--whole-archive
    internal
    signal
    thread
    mman
    string
    locale
    time
    temp
    errno
    dirent
    stdio
    -Wl,--no-whole-archive
)

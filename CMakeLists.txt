cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(msvc_dll_example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CMakeLists.warnings.cmake)

if(BUILD_WITH_ASAN)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
    message("-- build with ASAN enabled")
endif()

if(BUILD_WITH_UBSAN)
    add_compile_options(-fsanitize=undefined)
    add_link_options(-fsanitize=undefined)
    message("-- build with UBSAN enabled")
endif()

if(BUILD_WITH_ASAN OR BUILD_WITH_UBSAN)
   add_compile_options(-fno-var-tracking-assignments)
   #add_compile_options(-mcmodel=large)
   #add_compile_options(--param=max-vartrack-size=2500000)
   #add_link_options(-mcmodel=large)
   #add_compile_options(-Wl,--image-base -Wl,0x10000000)
endif()

add_subdirectory(src)

if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
   set(TARGETBITS 32)
else()
   set(TARGETBITS 64)
endif()

message("")
message("${PROJECT_NAME} configured to run on:  ${CMAKE_SYSTEM_NAME} ${TARGETBITS} bit, ${CMAKE_BUILD_TYPE} Mode")
message("${PROJECT_NAME} will be built in:      ${CMAKE_BINARY_DIR}")
message("${PROJECT_NAME} will be installed in:  ${CMAKE_INSTALL_PREFIX}")
message("\n")

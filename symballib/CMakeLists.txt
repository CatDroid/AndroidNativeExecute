# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(CMAKE_VERBOSE_MAKEFILE on)


add_library( # Sets the name of the library.
             symbal_lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/symbal.cpp )



find_library(log-lib log)

#set(CMAKE_C_VISIBILITY_PRESET hidden)
#set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fvisibility=hidden")
# 如果只设置了C_FLAGS不会对cpp文件有影响
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fvisibility=hidden")



target_link_libraries( # Specifies the target library.
                       symbal_lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
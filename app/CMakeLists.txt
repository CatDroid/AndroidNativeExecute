# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(CMAKE_VERBOSE_MAKEFILE on)

set(EXECUTABLE_OUTPUT_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/src/main/assets/${ANDROID_ABI}")


add_executable( # Sets the name of the library.
             native_exe

             # Sets the library as a shared library.
             #SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )



find_library(log-lib log)


target_link_libraries( # Specifies the target library.
                       native_exe

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
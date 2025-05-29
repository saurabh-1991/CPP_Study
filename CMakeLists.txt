# Minimum required CMake version
cmake_minimum_required(VERSION 3.20) # 3.20 or later for C++23 standard support

# Project name
project(cpp_study VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Prefer strict C++ standard

set(PREFERRED_COMPILERS_WINDOWS "MSVC" "cl.exe" "g++" "gcc")
set(PREFERRED_COMPILERS_UNIX "g++" "clang++") # Common names in PATH
set(MSVC_COMMON_PATHS
    "C:/Program Files/Microsoft Visual Studio/2022/Professional/VC/Tools/MSVC/14.38.33130/bin/Hostx64/x64/cl.exe"
)
set(ALL_PREFERRED_COMPILERS_PATH_HINTS
    ${MSVC_COMMON_PATHS}
    "C:/msys64/ucrt64/bin/gcc.exe"
    "C:/msys64/ucrt64/bin/g++.exe"
)
# Compiler-specific settings
if (MSVC)
    # Microsoft Visual C++ Compiler
    message(STATUS "Detected MSVC compiler.")
    # Add common MSVC compile options here, e.g., for warnings
    # For example: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
elseif (UNIX)
    # For Linux and macOS, which are both UNIX-like systems
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        # GCC compiler
        message(STATUS "Detected GCC compiler.")
        # Add common GCC compile options here, e.g., for warnings
        # For example: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
    elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        # Clang compiler
        message(STATUS "Detected Clang compiler.")
        # Add common Clang compile options here, e.g., for warnings
        # For example: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
    else()
        message(WARNING "Detected an unknown UNIX-like C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
    endif()
elseif (APPLE)
    message(STATUS "Detected Apple (macOS) operating system.")
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(STATUS "Detected Clang compiler on macOS.")
    else()
        message(WARNING "Detected an unknown C++ compiler on macOS: ${CMAKE_CXX_COMPILER_ID}")
    endif()
else()
    message(WARNING "Detected an unknown operating system.")
endif()

file(GLOB_RECURSE ALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/DesignPatterns/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Domain_CV/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Header_Files/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LeetCode_Problems/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SourceFiles/*.cpp"
)

# Add the main application source file if it exists in the root
set(MAIN_APP_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/cpp_study_main.cpp")
if (EXISTS "${MAIN_APP_SOURCE}")
    list(APPEND ALL_SOURCES "${MAIN_APP_SOURCE}")
else()
    message(WARNING "main.cpp not found in the project root. The main executable might not build correctly.")
endif()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/DesignPatterns"
    "${CMAKE_CURRENT_SOURCE_DIR}/Domain_CV"
    "${CMAKE_CURRENT_SOURCE_DIR}/Header_Files"
    "${CMAKE_CURRENT_SOURCE_DIR}/LeetCode_Problems"
    "${CMAKE_CURRENT_SOURCE_DIR}/SourceFiles"
)
# Create an executable target
add_executable(cpp_study ${ALL_SOURCES})
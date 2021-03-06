cmake_minimum_required(VERSION 3.6)

project(Karts VERSION 0.1 LANGUAGES CXX)
# Select C++ active standard
enable_language(CXX)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find some Git
find_package(Git QUIET)
if(NOT GIT_EXECUTABLE)
    find_program(GIT_EXECUTABLE git PATHS
        "$ENV{ProgramFiles}/Microsoft Visual Studio/*/*/Common7/IDE/CommonExtensions/Microsoft/TeamFoundation/Team Explorer/Git/cmd/"
        )
    find_package(Git)
endif()

# Fetch some OpenMind
include(FetchContent)
FetchContent_Declare(openmind GIT_REPOSITORY https://github.com/ohhmm/openmind.git GIT_TAG main)
FetchContent_MakeAvailable(openmind)

# Tell OpenMind to use any boost version installed in the system if any
option(OPENMIND_MATH_USE_LEVELDB_CACHE "Use Google LevelDB library to cache solutions" OFF)
find_package(Boost)
if(Boost_FOUND)
    set(OPENMIND_REQUIRED_BOOST_VERSION ${Boost_VERSION} CACHE VERSION "Boost library version to use" FORCE)
endif()


# Ask OpenMind to enable test projects creation (See WinnerTest)
option(OPENMIND_BUILD_TESTS "TESTS" ON)

# Ask OpenMind to iterate folders and create projects
fold()


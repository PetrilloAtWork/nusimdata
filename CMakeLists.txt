# ======================================================================
#  nusimdata main build file
#
# ======================================================================
# use cmake 3.3 or later
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

find_package(cetmodules 2.29.06 REQUIRED)
project(nusimdata VERSION 1.25.00 LANGUAGES CXX)

include(CetCMakeEnv)
cet_cmake_env()

# Find our own CMake modules, and tell everyone else where to find them.
cet_cmake_module_directories(Modules)

# -D_GLIBCXX_USE_NANOSLEEP is needed to make std::this_thread::sleep_for available.
cet_set_compiler_flags(DIAGS CAUTIOUS WERROR 
                       NO_UNDEFINED
                       EXTRA_FLAGS -pedantic 
                                   $<$<COMPILE_LANGUAGE:CXX>:-D_GLIBCXX_USE_NANOSLEEP 
                                   -Wno-unused-local-typedefs -Wno-variadic-macros>)
cet_report_compiler_flags(REPORT_THRESHOLD VERBOSE)

find_package(cetlib REQUIRED)
find_package(canvas REQUIRED)
find_package(canvas_root_io REQUIRED) # Needed for art_dictionary().
find_package(dk2nudata REQUIRED)

# macros
include(CetMake)
include(ArtDictionary)
include(BasicPlugin)

# source
add_subdirectory (nusimdata)
add_subdirectory (test)
add_subdirectory (Modules)

# ups - table and config files
# packaging utility
cet_cmake_config()

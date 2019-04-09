# ======================================================================
#  nusimdata main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/nusimdata/ups/setup_for_development
#  cmake [-DCMAKE_INSTALL_PREFIX=/install/path]
#        -DCMAKE_BUILD_TYPE=$CETPKG_TYPE
#        $CETPKG_SOURCE
#        
#  make
#  make test
#  make install
#  make package (builds distribution tarfile)
# ======================================================================


# use cmake 3.3 or later
cmake_minimum_required (VERSION 3.3)

project(nusimdata VERSION 1.21.02 LANGUAGES CXX)

set(fcl_dir fcl)
find_package(cetmodules REQUIRED)
include(CetCMakeEnv)
cet_cmake_env()

# -D_GLIBCXX_USE_NANOSLEEP is needed to make std::this_thread::sleep_for available.
cet_set_compiler_flags(DIAGS CAUTIOUS WERROR 
                       NO_UNDEFINED
                       EXTRA_FLAGS -pedantic 
                       EXTRA_CXX_FLAGS -D_GLIBCXX_USE_NANOSLEEP 
                                       -Wno-unused-local-typedefs -Wno-variadic-macros)
cet_report_compiler_flags()

# these are minimum required versions, not the actual product versions
find_package( canvas_root_io REQUIRED )
# macros 
include(CetMake)
include(ArtDictionary)
include(BasicPlugin)

# source
add_subdirectory (nusimdata)
add_subdirectory (test)
add_subdirectory(cmakeConfig)

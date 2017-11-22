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

project(nusimdata)

# cetbuildtools contains our cmake modules
SET ( CETBUILDTOOLS_VERSION $ENV{CETBUILDTOOLS_VERSION} )
IF (NOT CETBUILDTOOLS_VERSION)
    MESSAGE (FATAL_ERROR "ERROR: setup cetbuildtools to get the cmake modules")
ENDIF()

set(CMAKE_MODULE_PATH $ENV{CANVAS_DIR}/Modules
                      $ENV{CETBUILDTOOLS_DIR}/Modules
                      ${CMAKE_MODULE_PATH})

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
find_ups_product( canvas )
find_ups_product( cetbuildtools )
find_ups_root(  )

# macros 
include(CetMake)
include(ArtDictionary)
include(BasicPlugin)

# source
add_subdirectory (nusimdata)
add_subdirectory (test)

# ups - table and config files
add_subdirectory(ups)
# packaging utility
include(UseCPack)

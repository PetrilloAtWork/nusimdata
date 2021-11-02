#[================================================================[.rst:
Finddk2nudata
----------
  find dk2nugenie

#]================================================================]
if (dk2nudata_FIND_REQUIRED)
  set(_cet_dk2nudata_FIND_REQUIRED ${dk2nudata_FIND_REQUIRED})
  unset(dk2nudata_FIND_REQUIRED)
else()
  unset(_cet_dk2nudata_FIND_REQUIRED)
endif()
find_package(dk2nudata CONFIG QUIET)
if (_cet_dk2nudata_FIND_REQUIRED)
  set(dk2nudata_FIND_REQUIRED ${_cet_dk2nudata_FIND_REQUIRED})
  unset(_cet_dk2nudata_FIND_REQUIRED)
endif()
if (dk2nudata_FOUND)
  set(_cet_dk2nudata_config_mode CONFIG_MODE)
else()
  unset(_cet_dk2nudata_config_mode)
  find_file(_cet_dk2nu_h NAMES dk2nu.h HINTS ENV DK2NUDATA_INC
    PATH_SUFFIXES dk2nu/tree)
  if (_cet_dk2nu_h)
    get_filename_component(_cet_dk2nudata_include_dir "${_cet_dk2nu_h}" PATH)
    get_filename_component(_cet_dk2nudata_include_dir "${_cet_dk2nudata_include_dir}" PATH)
    get_filename_component(_cet_dk2nudata_include_dir "${_cet_dk2nudata_include_dir}" PATH)
    if (_cet_dk2nudata_include_dir STREQUAL "/")
      unset(_cet_dk2nudata_include_dir)
    endif()
  endif()
  if (EXISTS "${_cet_dk2nudata_include_dir}")
    set(dk2nudata_FOUND TRUE)
    set(DK2NUDATA_FOUND TRUE)
    get_filename_component(_cet_dk2nudata_dir "${_cet_dk2nudata_include_dir}" PATH)
    if (_cet_dk2nudata_dir STREQUAL "/")
      unset(_cet_dk2nudata_dir)
    endif()
    set(dk2nudata_INCLUDE_DIRS "${_cet_dk2nudata_include_dir}")
    set(dk2nudata_LIBRARY_DIR "${_cet_dk2nudata_dir}/lib")
    find_library(dk2nudata_LIBRARY NAMES dk2nuTree HINTS ${dk2nudata_LIBRARY_DIR})
  endif()
endif()
if (dk2nudata_FOUND)
  if (NOT TARGET dk2nu::Tree)
    add_library(dk2nu::Tree SHARED IMPORTED)
    set_target_properties(dk2nu::Tree PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${dk2nudata_INCLUDE_DIRS}"
      IMPORTED_LOCATION "${dk2nudata_LIBRARY}"
      )
    set(dk2nudata_LIBRARY "dk2nu::Tree")
  endif()
  if (CETMODULES_CURRENT_PROJECT_NAME AND
      ${CETMODULES_CURRENT_PROJECT_NAME}_OLD_STYLE_CONFIG_VARS)
    include_directories("${dk2nudata_INCLUDE_DIRS}")
    set(DK2NUDATA "${dk2nudata_LIBRARY}")
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(dk2nudata ${_cet_dk2nudata_config_mode}
  REQUIRED_VARS dk2nudata_FOUND
  dk2nudata_INCLUDE_DIRS
  dk2nudata_LIBRARY)

unset(_cet_dk2nudata_FIND_REQUIRED)
unset(_cet_dk2nudata_config_mode)
unset(_cet_dk2nudata_dir)
unset(_cet_dk2nudata_include_dir)
unset(_cet_dk2nu_h CACHE)


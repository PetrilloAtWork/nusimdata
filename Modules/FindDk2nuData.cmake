#[================================================================[.rst:
FindDk2nuData
----------
  find dk2nugenie

#]================================================================]
if (Dk2nuData_FIND_REQUIRED)
  set(_cet_Dk2nuData_FIND_REQUIRED ${Dk2nuData_FIND_REQUIRED})
  unset(Dk2nuData_FIND_REQUIRED)
else()
  unset(_cet_Dk2nuData_FIND_REQUIRED)
endif()
find_package(Dk2nuData CONFIG QUIET)
if (_cet_Dk2nuData_FIND_REQUIRED)
  set(Dk2nuData_FIND_REQUIRED ${_cet_Dk2nuData_FIND_REQUIRED})
  unset(_cet_Dk2nuData_FIND_REQUIRED)
endif()
if (Dk2nuData_FOUND)
  set(_cet_Dk2nuData_config_mode CONFIG_MODE)
else()
  unset(_cet_Dk2nuData_config_mode)
  find_file(_cet_dk2nu_h NAMES dk2nu.h HINTS ENV DK2NUDATA_INC
    PATH_SUFFIXES dk2nu/tree)
  if (_cet_dk2nu_h)
    get_filename_component(_cet_Dk2nuData_include_dir "${_cet_dk2nu_h}" PATH)
    get_filename_component(_cet_Dk2nuData_include_dir "${_cet_Dk2nuData_include_dir}" PATH)
    get_filename_component(_cet_Dk2nuData_include_dir "${_cet_Dk2nuData_include_dir}" PATH)
    if (_cet_Dk2nuData_include_dir STREQUAL "/")
      unset(_cet_Dk2nuData_include_dir)
    endif()
  endif()
  if (EXISTS "${_cet_Dk2nuData_include_dir}")
    set(Dk2nuData_FOUND TRUE)
    set(DK2NUDATA_FOUND TRUE)
    get_filename_component(_cet_Dk2nuData_dir "${_cet_Dk2nuData_include_dir}" PATH)
    if (_cet_Dk2nuData_dir STREQUAL "/")
      unset(_cet_Dk2nuData_dir)
    endif()
    set(Dk2nuData_INCLUDE_DIRS "${_cet_Dk2nuData_include_dir}")
    set(Dk2nuData_LIBRARY_DIR "${_cet_Dk2nuData_dir}/lib}")
    find_library(Dk2nuData_LIBRARY NAMES dk2nuTree HINTS ${Dk2nuData_LIBRARY_DIR})
  endif()
endif()
if (Dk2nuData_FOUND)
  if (NOT TARGET Dk2nuData::dk2nuTree)
    add_library(Dk2nuData::dk2nuTree SHARED IMPORTED)
    set_target_properties(Dk2nuData::dk2nuTree PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${Dk2nuData_INCLUDE_DIRS}"
      IMPORTED_LOCATION "${Dk2nuData_LIBRARY}"
      )
    set(Dk2nuData_LIBRARY "Dk2nuData::dk2nuTree")
  endif()
  if (CETMODULES_CURRENT_PROJECT_NAME AND
      ${CETMODULES_CURRENT_PROJECT_NAME}_OLD_STYLE_CONFIG_VARS)
    include_directories("${Dk2nuData_INCLUDE_DIRS}")
    set(DK2NUDATA "${Dk2nuData_LIBRARY")
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Dk2nuData ${_cet_Dk2nuData_config_mode}
  REQUIRED_VARS Dk2nuData_FOUND
  Dk2nuData_INCLUDE_DIRS
  Dk2nuData_LIBRARY)

unset(_cet_Dk2nuData_FIND_REQUIRED)
unset(_cet_Dk2nuData_config_mode)
unset(_cet_Dk2nuData_dir)
unset(_cet_Dk2nuData_include_dir)
unset(_cet_dk2nu_h CACHE)


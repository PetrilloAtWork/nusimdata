#[================================================================[.rst:
FindDk2nuData
----------
  find dk2nugenie

#]================================================================]
if (NOT Dk2nuData_FOUND)
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
  endif()
endif()
if (NOT Dk2nuData_FOUND)
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
  endif()
endif()
if (Dk2nuData_FOUND AND _cet_Dk2nuData_include_dir)
  if (TARGET ${CMAKE_FIND_PACKAGE_NAME}::dk2nuTree)
    set(Dk2nuData_LIBRARY "${CMAKE_FIND_PACKAGE_NAME}::dk2nuTree")
    target_include_directories(${Dk2nuData_LIBRARY} AFTER INTERFACE ${_cet_Dk2nuData_include_dir})
  else()
    message(STATUS "finding Dk2nuData_LIBRARY")
    find_library(Dk2nuData_LIBRARY NAMES dk2nuTree PATHS ENV DK2NUDATA_LIB REQUIRED)
    add_library(Dk2nuData::dk2nuTree UNKNOWN IMPORTED)
    set_target_properties(Dk2nuData::dk2nuTree PROPERTIES
      IMPORTED_LOCATION "${Dk2nuData_LIBRARY}"
      INTERFACE_INCLUDE_DIRECTORIES "${Dk2nuData_INCLUDE_DIR}")
  endif()
endif()
message(STATUS "_cet_Dk2nuData_include_dir is ${_cet_Dk2nuData_include_dir}")
include_directories("${_cet_Dk2nuData_include_dir}")
set(${CMAKE_FIND_PACKAGE_NAME}_INCLUDE_DIR "${_cet_Dk2nuData_include_dir}")
set(Dk2nuData_FIND_REQUIRED ${_cet_Dk2nuData_FIND_REQUIRED})
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Dk2nuData
  FOUND_VAR Dk2nuData_FOUND
  REQUIRED_VARS
    Dk2nuData_LIBRARY
    Dk2nuData_INCLUDE_DIR
)
if(Dk2nuData_FOUND)
  set(Dk2nuData_LIBRARIES ${Dk2nuData_LIBRARY})
  set(Dk2nuData_INCLUDE_DIRS ${Dk2nuData_INCLUDE_DIR})
  set(Dk2nuData_DIR "${_cet_Dk2nuData_dir}")
endif()


unset(_cet_Dk2nuData_FIND_REQUIRED)
unset(_cet_Dk2nuData_config_mode)
unset(_cet_Dk2nuData_dir)
unset(_cet_Dk2nuData_include_dir)
unset(_cet_dk2nu_h CACHE)


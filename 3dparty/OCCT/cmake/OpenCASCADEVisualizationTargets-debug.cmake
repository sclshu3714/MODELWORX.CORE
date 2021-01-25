#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "TKService" for configuration "Debug"
set_property(TARGET TKService APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKService PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/win32/vc14/libd/TKService.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/win32/vc14/bind/TKService.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TKService )
list(APPEND _IMPORT_CHECK_FILES_FOR_TKService "${_IMPORT_PREFIX}/win32/vc14/libd/TKService.lib" "${_IMPORT_PREFIX}/win32/vc14/bind/TKService.dll" )

# Import target "TKV3d" for configuration "Debug"
set_property(TARGET TKV3d APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKV3d PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/win32/vc14/libd/TKV3d.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/win32/vc14/bind/TKV3d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TKV3d )
list(APPEND _IMPORT_CHECK_FILES_FOR_TKV3d "${_IMPORT_PREFIX}/win32/vc14/libd/TKV3d.lib" "${_IMPORT_PREFIX}/win32/vc14/bind/TKV3d.dll" )

# Import target "TKOpenGl" for configuration "Debug"
set_property(TARGET TKOpenGl APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKOpenGl PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/win32/vc14/libd/TKOpenGl.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/win32/vc14/bind/TKOpenGl.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TKOpenGl )
list(APPEND _IMPORT_CHECK_FILES_FOR_TKOpenGl "${_IMPORT_PREFIX}/win32/vc14/libd/TKOpenGl.lib" "${_IMPORT_PREFIX}/win32/vc14/bind/TKOpenGl.dll" )

# Import target "TKMeshVS" for configuration "Debug"
set_property(TARGET TKMeshVS APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKMeshVS PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/win32/vc14/libd/TKMeshVS.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/win32/vc14/bind/TKMeshVS.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TKMeshVS )
list(APPEND _IMPORT_CHECK_FILES_FOR_TKMeshVS "${_IMPORT_PREFIX}/win32/vc14/libd/TKMeshVS.lib" "${_IMPORT_PREFIX}/win32/vc14/bind/TKMeshVS.dll" )

# Import target "TKIVtk" for configuration "Debug"
set_property(TARGET TKIVtk APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKIVtk PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/win32/vc14/libd/TKIVtk.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/win32/vc14/bind/TKIVtk.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TKIVtk )
list(APPEND _IMPORT_CHECK_FILES_FOR_TKIVtk "${_IMPORT_PREFIX}/win32/vc14/libd/TKIVtk.lib" "${_IMPORT_PREFIX}/win32/vc14/bind/TKIVtk.dll" )

# Import target "TKD3DHost" for configuration "Debug"
set_property(TARGET TKD3DHost APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(TKD3DHost PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/win32/vc14/libd/TKD3DHost.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/win32/vc14/bind/TKD3DHost.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS TKD3DHost )
list(APPEND _IMPORT_CHECK_FILES_FOR_TKD3DHost "${_IMPORT_PREFIX}/win32/vc14/libd/TKD3DHost.lib" "${_IMPORT_PREFIX}/win32/vc14/bind/TKD3DHost.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

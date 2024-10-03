# - This module determines the mgplus library of the system
# The following variables are set if the library found:
# MGPLUS_FOUND - If false do nnt try to use mgplus.
# MGPLUS_INCLUDE_DIR - where to find the headfile of library.
# MGPLUS_LIBRARY_DIR - where to find the mgplus library.
# MGPLUS_LIBRARY - the library needed to use mgplus.

# find the headfile of library

set (MGPLUS_HEADS mgplus/mgplus.h)
find_path (MGPLUS_INCLUDE_DIR ${MGPLUS_HEADS})

set (MGPLUS_NAMES mgplus libmgplus)
find_library (MGPLUS_LIBRARY NAMES ${MGPLUS_NAMES})

# just find one of dependency, guess other one.
if (NOT MGPLUS_LIBRARY AND MGPLUS_INCLUDE_DIR)
	message ("We just find the headfile, try to guess the library location.")
	set (MGPLUS_LIBRARY_DIR "${MGPLUS_INCLUDE_DIR}/../lib")
	find_library (MGPLUS_LIBRARY NAMES ${MGPLUS_NAMES} PATHS ${MGPLUS_LIBRARY_DIR})
elseif (NOT MGPLUS_INCLUDE_DIR AND MGPLUS_LIBRARY)
	message ("We just find the lib file, try to guess the include location.")
	string (REGEX REPLACE "[a-z|A-Z|0-9|_|-]+[.].*$" "" MGPLUS_LIBRARY_DIR ${MGPLUS_LIBRARY})
	find_path (MGPLUS_INCLUDE_DIR ${MGPLUS_HEADS} "${MGPLUS_LIBRARY_DIR}../included")
endif()

# find the library.
if (MGPLUS_INCLUDE_DIR AND MGPLUS_LIBRARY)
	set (MGPLUS_FOUND TRUE)
	if (NOT MGPLUS_LIBRARY_DIR)
		string (REGEX REPLACE "[a-z|A-Z|0-9|_|-]+[.].*$" "" MGPLUS_LIBRARY_DIR ${MGPLUS_LIBRARY})
	endif ()
    string (REGEX MATCH "[a-z|A-Z|0-9|_|-]+[.](a|so|lib|dll|LIB|DLL)[^/]*$" MGPLUS_LIBRARY_WHOLE_NAME "${MGPLUS_LIBRARY}")
    string (REGEX MATCH "[^(lib)][a-z|A-Z|0-9|_|-]+" MGPLUS_LIBRARIES ${MGPLUS_LIBRARY_WHOLE_NAME})
	message (STATUS "Find MGPLUS include in ${MGPLUS_INCLUDE_DIR}")
	message (STATUS "Find MGPLUS library in ${MGPLUS_LIBRARY}")
else ()
	message (STATUS "Could NOT find MGPLUS, (missing: MGPLUS_INCLUDE_DIR MGPLUS_LIBRARY)")
endif ()


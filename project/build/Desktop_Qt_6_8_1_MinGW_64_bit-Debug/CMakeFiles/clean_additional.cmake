# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Finalproject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Finalproject_autogen.dir\\ParseCache.txt"
  "Finalproject_autogen"
  )
endif()

# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ComputerShop_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ComputerShop_autogen.dir\\ParseCache.txt"
  "ComputerShop_autogen"
  )
endif()

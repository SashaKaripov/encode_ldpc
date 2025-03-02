# Install script for directory: D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MyProject")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Program Files/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/AdolcForward"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/AlignedVector3"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/ArpackSupport"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/AutoDiff"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/BVH"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/EulerAngles"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/FFT"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/IterativeSolvers"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/KroneckerProduct"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/LevenbergMarquardt"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/MatrixFunctions"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/MPRealSupport"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/NNLS"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/NonLinearOptimization"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/NumericalDiff"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/OpenGLSupport"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/Polynomials"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/SparseExtra"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/SpecialFunctions"
    "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/Splines"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "D:/hmmmmm/build/_deps/eigen-src/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/hmmmmm/build/_deps/eigen-build/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()


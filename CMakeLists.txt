CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(FGCore)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/external
  ${CMAKE_CURRENT_SOURCE_DIR}/external/gtest/include #gtest
  ${CMAKE_CURRENT_SOURCE_DIR}/external/gtest/        #gtest
  ${CMAKE_CURRENT_SOURCE_DIR}/external/clsocket/src  #clsocket
)

# set compile files by src folder.
# AUX_SOURCE_DIRECTORY(src/base SRC_LIST)
# AUX_SOURCE_DIRECTORY(src/network/socket SRC_LIST)
# AUX_SOURCE_DIRECTORY(src/network SRC_LIST)
# AUX_SOURCE_DIRECTORY(src SRC_LIST)

#FGCore
AUX_SOURCE_DIRECTORY(src SRC_LIST)
ADD_LIBRARY(FGCore STATIC ${SRC_LIST})

#FGCore Gtest
set(GTEST_FGCORE_SRCS
	test/fgtest-all.cc
	external/gtest/src/gtest-all.cc
	external/gtest/src/gtest_main.cc
)
add_executable(FGCoreGTest ${GTEST_FGCORE_SRCS})

#### for simple socket
if(UNIX)
    # linux / normal unix
    add_definitions(-D_LINUX)
    if(CYGWIN)
        # Special Cygwin stuff here
    elseif(APPLE)
        # Special Apple stuff here
        remove_definitions(-D_LINUX)
        add_definitions(-D_DARWIN)
    endif()
elseif(WIN32)
    add_definitions(-DWIN32)
    SET(PROJECT_LIBS Ws2_32.lib)
    if(MINGW)
        # Special MINGW stuff here
    elseif(MSVC)
        # Special MSVC stuff here
        add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
    else()
        # No idea what it is, but there's a good chance it's too weird.
        MESSAGE( FATAL_ERROR "Using unknown WIN32 compiler... NOT. Please add to build system." )
    endif()
endif()

# IF (APPLE)
# 	add_compile_options(-x objective-c++)
# 	set(CMAKE_EXE_LINKER_FLAGS "-framework CFNetwork.framework")
# ENDIF(APPLE)

#c++ 11 supports
include(CheckCXXCompilerFlag)  
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)  
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)  

add_definitions("-Wundefined-internal")

if(COMPILER_SUPPORTS_CXX11)  
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  
elseif(COMPILER_SUPPORTS_CXX0X)  
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")  
else()  
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")  
endif()  
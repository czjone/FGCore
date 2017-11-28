CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(FGCore)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/external
)
AUX_SOURCE_DIRECTORY(src/base SRC_LIST)
AUX_SOURCE_DIRECTORY(src/network/socket SRC_LIST)
AUX_SOURCE_DIRECTORY(src/network SRC_LIST)
AUX_SOURCE_DIRECTORY(src SRC_LIST)
ADD_LIBRARY(FGCore STATIC ${SRC_LIST})

IF (APPLE)
	add_compile_options(-x objective-c++)
	set(CMAKE_EXE_LINKER_FLAGS "-framework CFNetwork.framework")
ENDIF(APPLE)

#c++ 11 supports
include(CheckCXXCompilerFlag)  
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)  
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)  
if(COMPILER_SUPPORTS_CXX11)  
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  
elseif(COMPILER_SUPPORTS_CXX0X)  
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")  
else()  
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")  
endif()  
project(StaffManagerSystem)

cmake_minimum_required(VERSION 3.0)

message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})

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

add_subdirectory(Cpp)
add_subdirectory(header)

include_directories(${PROJECT_SOURCE_DIR}/header)
aux_source_directory(${PROJECT_SOURCE_DIR}/Cpp src_list)

# set(LIB_SRC Boss.cpp Manager.cpp Staff.cpp WorkerManage.cpp ManageSystem.cpp)
set(LIB_SRC Boss.cpp Manager.cpp Staff.cpp WorkerManage.cpp)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_library(DBlib SHARED ${src_list})

add_executable(StaffManageSystem ManageSystem.cpp)
target_link_libraries(StaffManageSystem DBlib)
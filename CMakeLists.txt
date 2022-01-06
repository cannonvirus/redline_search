cmake_minimum_required(VERSION 3.0.0)
project(histo VERSION 0.1.0)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(CPACK_PROJECT_NAME ${PROJECT_NAME})
SET(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
else ()
    message(FATAL_ERROR "Could not locate OpenCV")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(histo main.cpp ./src/redline_search.cpp)

target_link_libraries (
        ${CMAKE_PROJECT_NAME}
        ${OpenCV_LIBS}
)

include(CPack)

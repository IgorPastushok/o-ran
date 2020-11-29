cmake_minimum_required(VERSION 3.17)
project(o_ran)

set(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE( Boost 1.74 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(o_ran main.cpp writer/IWriter.h reader/IReader.h writer/ConsoleWriter.cpp writer/ConsoleWriter.h writer/HTTPWriter.cpp writer/HTTPWriter.h reader/JSONReader.cpp reader/JSONReader.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED)
target_link_libraries(o_ran PRIVATE Threads::Threads ${Boost_LIBRARIES})

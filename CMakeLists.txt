cmake_minimum_required(VERSION 3.17)
project(o_ran)

set(CMAKE_CXX_STANDARD 20)



add_executable(o_ran main.cpp IWriter.h IReader.h ConsoleWriter.cpp ConsoleWriter.h HTTPWriter.cpp HTTPWriter.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(o_ran PRIVATE Threads::Threads)
cmake_minimum_required(VERSION 2.8)

project(ServiceRGB)

enable_testing()


#Add include directories
include_directories(inc)
include_directories(src)

#if build in project
include_directories(../ServiceDispatcher/inc)
#if build for test
#include_directories(test)


#Add sources
set(srcs
    src/serviceRGBClient.c
    src/serviceRGBServer.c )


#Add Library
add_library(ServiceRGB SHARED ${srcs})

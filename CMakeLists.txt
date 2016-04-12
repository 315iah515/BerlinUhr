cmake_minimum_required (VERSION 2.6)

project(BerlinUhr)

find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTORCC ON)

#QT5_WRAP_CPP(Source_hdr_moc source/oscillwidget.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)

#add_library(MOCcode ${Source_hdr_moc} )
#target_compile_options(MOCcode PUBLIC -std=c++14)

#qt5_use_modules(MOCcode Widgets)

set (HEADERS header/berlin_clock.hpp)

set (SOURCE  source/main.cpp
     source/berlin_clock.cpp)

add_executable(BerlinUhr ${HEADERS} ${SOURCE} )
qt5_use_modules(BerlinUhr Core Gui Widgets)

target_compile_options(BerlinUhr PUBLIC -std=c++14)


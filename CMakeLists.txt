cmake_minimum_required(VERSION 2.8)

project(3d-recon)

FIND_PACKAGE( OpenCV REQUIRED )

FIND_PACKAGE( Threads REQUIRED )

add_executable(3d-recon main.cpp)

TARGET_LINK_LIBRARIES( 3d-recon ${OpenCV_LIBS} )





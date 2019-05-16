cmake_minimum_required( VERSION 3.2 )
project( Signal-IO-OpenSim )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -O3 -march=native -mtune=native -D EIGEN_NO_DEBUG" )

set( EIGEN_ROOT $ENV{EIGEN_ROOT} CACHE PATH "Path to Eigen headers" )

include( ${CMAKE_CURRENT_LIST_DIR}/robot_control/CMakeLists.txt )

include_directories( ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/ct/ct_core/include ${CMAKE_CURRENT_LIST_DIR}/ct/ct_optcon/include ${CMAKE_CURRENT_LIST_DIR}/ct/ct_rbd/include ${EIGEN_ROOT} )

set( M2L_DIR ${CMAKE_CURRENT_LIST_DIR}/gen/m2l/cpp/ )
add_library( CTM2LRobot MODULE  ${CMAKE_CURRENT_LIST_DIR}/m2l_robot.cpp )
target_include_directories( CTM2LRobot ${M2L_DIR} )
set_target_properties( CTM2LRobot PROPERTIES PREFIX "" )
#target_link_libraries( CTM2LRobot )

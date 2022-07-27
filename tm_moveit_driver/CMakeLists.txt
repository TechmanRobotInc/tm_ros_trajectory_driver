cmake_minimum_required(VERSION 3.0.2)
project(tm_trajectory_driver)

add_definitions(-DROS_BUILD)
add_definitions(-DUSE_BOOST)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tm_msgs
  moveit_ros_planning_interface
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS actionlib control_msgs geometry_msgs roscpp sensor_msgs #hardware_interface controller_manager
  #DEPENDS tm_hardware_interface
)
#endif()

###########
## Build ##
###########

#if(NOT BOOST_FLAG)
  include(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX11)
  #CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
  if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "-std=c++14")
  #elseif(COMPILER_SUPPORTS_CXX0X)
  #  set(CMAKE_CXX_FLAGS "-std=c++0x")
  else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
  endif()
#endif()

## Specify additional locations of header files
include_directories(include
  ${catkin_INCLUDE_DIRS}
)

set(${PROJECT_NAME}_SOURCES
  src/tm_trajectory_driver.cpp
  src/fake_move_robot.cpp
  src/tm_moveit_robot.cpp
)
add_executable(tm_trajectory_driver ${${PROJECT_NAME}_SOURCES})

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(tm_trajectory_driver ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(tm_trajectory_driver
#  tm_hardware_interface
  ${catkin_LIBRARIES}
)

add_executable(test_tm_trajectory_driver test/test_ros_connection.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(test_tm_trajectory_driver ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(test_tm_trajectory_driver
#  tm_hardware_interface
  ${catkin_LIBRARIES}
)

add_executable(test_run_tm_trajectory_robot test/test_run_tm_trajectory_robot.cpp src/tm_moveit_robot.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(test_run_tm_trajectory_robot ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(test_run_tm_trajectory_robot
#  tm_hardware_interface
  ${catkin_LIBRARIES}
)

add_executable(joint_move_demo demo/joint_move_demo.cpp )

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(joint_move_demo ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(joint_move_demo
#  tm_hardware_interface
  ${catkin_LIBRARIES}
)

add_executable(cartisian_move_demo demo/cartisian_move_demo.cpp )

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(cartisian_move_demo ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(cartisian_move_demo
#  tm_hardware_interface
  ${catkin_LIBRARIES}
)
#############
## Install ##
#############

install(TARGETS cartisian_move_demo #tm_hardware_interface
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS joint_move_demo #tm_hardware_interface
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS tm_trajectory_driver #tm_hardware_interface
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS test_tm_trajectory_driver #tm_hardware_interface
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS test_run_tm_trajectory_robot #tm_hardware_interface
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
## Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

#############
## Testing ##
#############


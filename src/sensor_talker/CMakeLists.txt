cmake_minimum_required(VERSION 3.16.3)
project(sensor_talker VERSION 0.1.0 LANGUAGES C CXX)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs 
)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp std_msgs  
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

file(GLOB sensortalker_SOURCES src/sensor_talker/*.cpp )
add_library(sensortalkerlib STATIC ${sensortalker_SOURCES})

add_executable("${PROJECT_NAME}_node" src/sensor_talker.cpp  ) 

add_dependencies("${PROJECT_NAME}_node" ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})



target_link_libraries("${PROJECT_NAME}_node" PUBLIC sensortalkerlib ${catkin_LIBRARIES})

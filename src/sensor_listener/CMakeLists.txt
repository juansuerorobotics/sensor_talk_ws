cmake_minimum_required(VERSION 3.16.3)
project(sensor_listener VERSION 0.1.0 LANGUAGES C CXX)

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

file(GLOB sensor_SOURCES src/sensor/*.cpp )
add_library(sensorlib STATIC ${sensor_SOURCES})

add_executable("${PROJECT_NAME}_node" src/sensor_listener.cpp  ) 

add_dependencies("${PROJECT_NAME}_node" ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})



target_link_libraries("${PROJECT_NAME}_node" PUBLIC sensorlib ${catkin_LIBRARIES})




add_executable(sensor_test tests/sensor_test.cpp src/sensor/sensor_datatypes.cpp include/sensor/sensor_datatypes.h src/sensor/sensor_drivers_test.cpp include/sensor/sensor_drivers_test.h ) 



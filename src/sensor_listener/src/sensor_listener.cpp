

#include "sensor/sensor_drivers.h"
#include <iostream>
#include "ros/ros.h"

using namespace std;

int main(int argc, char *argv[])
{
    // std::cout << "Program start" << std::endl;
    // sensor_driver_test();

    ros::init(argc, argv, "sensor_listener_node");

    SensorDriver sensor_driver = SensorDriver();

    ros::Rate loop_rate(30);

    while (ros::ok())
    {
        sensor_driver.update();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
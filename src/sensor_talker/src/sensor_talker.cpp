

#include "sensor_talker/sensor_talker_driver.h"
#include <iostream>
#include "ros/ros.h"

using namespace std;

int main(int argc, char *argv[])
{


    ros::init(argc, argv, "sensor_talker_node");

    SensorTalkerDriver sensor_talker_driver = SensorTalkerDriver();

    ros::Rate loop_rate(30);

    while (ros::ok())
    {
        sensor_talker_driver.update();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
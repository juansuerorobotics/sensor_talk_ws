
#include "sensor_talker/sensor_talker_driver.h"
#include <iostream>
#include "ros/ros.h"
#include <string>

SensorTalkerDriver::SensorTalkerDriver() : _nh_priv("~")
{
    bool init_results = init();
}

bool SensorTalkerDriver::init()
{
     
    _nh.getParam("sensor_numreadings", _sensor_numreadings);


    ROS_INFO("_sensor_numreadings: [%d]", _sensor_numreadings);

    // initialize publishers
    _sensor_readings_pub = _nh.advertise<std_msgs::String>("sensor_readings", 100);

    return true;
}

bool SensorTalkerDriver::update()
{

    //ROS_INFO("I heard: [%d]", _sensor_numreadings);

     

    for (int i = 1; i <= _sensor_numreadings; i++)
    {
        std_msgs::String sensor_readings_pub_msg;
         
        sensor_readings_pub_msg.data = std::to_string( (float)i );
        _sensor_readings_pub.publish(sensor_readings_pub_msg);
    }

    return true;
}

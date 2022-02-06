
#include "sensor/sensor_datatypes.h"
#include "sensor/sensor_drivers.h"
#include <iostream>

SensorDriver::SensorDriver() : _nh_priv("~")
{
    bool init_results = init();
}

bool SensorDriver::init()
{

    int sensor_span;

    _nh.getParam("sensor_span", sensor_span);
    ROS_INFO("I heard sensor_span : [%d]", sensor_span);
    _sensor = Sensor(sensor_span);

    // initialize subscribers
    _sensor_readings_sub = _nh.subscribe("sensor_readings", 100, &SensorDriver::sensorReadingsCallback, this);

    // initialize publishers
    _sensor_running_avg_pub = _nh.advertise<std_msgs::String>("sensor_running_avg", 100);

    return true;
}

bool SensorDriver::update()
{
    std_msgs::String sensor_running_avg_msg;
    float runningAverage = _sensor.GetRunningAverage();
    // ROS_INFO("I heard runningAverage : [%f]", runningAverage);
    // ROS_INFO("I heard std::to_string( runningAverage ) : [%s]", std::to_string(runningAverage).c_str());
    sensor_running_avg_msg.data = std::to_string(runningAverage);
    _sensor_running_avg_pub.publish(sensor_running_avg_msg);

    return true;
}

void SensorDriver::updateSensor()
{
}

void SensorDriver::sensorReadingsCallback(const std_msgs::String::ConstPtr &sensor_readings_msg)
{
    // ROS_INFO("I heard sensorReadingsCallback : [%s]", sensor_readings_msg->data.c_str());
    // ROS_INFO("I heard sensorReadingsCallback : [%f]", std::stof(sensor_readings_msg->data.c_str()));
    _sensor.AddToRunningAverage(std::stof(sensor_readings_msg->data.c_str()));
}

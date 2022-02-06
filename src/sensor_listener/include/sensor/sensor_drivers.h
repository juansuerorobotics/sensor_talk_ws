
#ifndef SENSOR_DRIVERS_H_
#define SENSOR_DRIVERS_H_


#include <ros/ros.h>
#include "sensor/sensor_datatypes.h"
#include "std_msgs/String.h"



class SensorDriver
{
    public:
        SensorDriver() ; 
        bool init();
        bool update();
        void updateSensor();

    private:
        ros::NodeHandle _nh;
        ros::NodeHandle _nh_priv;

        ros::Subscriber _sensor_readings_sub;

        ros::Publisher _sensor_running_avg_pub;

        Sensor _sensor;

        void sensorReadingsCallback(const std_msgs::String::ConstPtr& sensor_readings_msg);


};

void sensor_driver_test();


#endif // SENSOR_DRIVERS_H_

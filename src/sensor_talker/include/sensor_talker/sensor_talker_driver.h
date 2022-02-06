
#ifndef SENSOR_TALKER_DRIVER_H_
#define SENSOR_TALKER_DRIVER_H_


#include <ros/ros.h> 
#include "std_msgs/String.h"



class SensorTalkerDriver
{
    public:
        SensorTalkerDriver() ; 
        bool init();
        bool update();
         

    private:
        ros::NodeHandle _nh;
        ros::NodeHandle _nh_priv;
 
        ros::Publisher _sensor_readings_pub;
        int _sensor_numreadings;

};

 


#endif // SENSOR_TALKER_DRIVER_H_

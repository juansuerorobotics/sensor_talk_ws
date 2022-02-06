
#include "sensor/sensor_datatypes.h"
#include "sensor/sensor_drivers_test.h"

 

#include <iostream>


void sensor_driver_test()
{

    int sensorSpan = 10;

    Sensor sensor = Sensor(sensorSpan);

    int numReadings = 10;

    while (true)
    {
        for (int i = 1; i <= numReadings; i++)
        {
            sensor.AddToRunningAverage((float)i);
        }

        float runningAverage = sensor.GetRunningAverage();
        printf("runningAverage: %f\n", runningAverage);
    }
}
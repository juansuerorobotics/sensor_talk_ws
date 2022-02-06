#ifndef SENSOR_DATATYPES_H_
#define SENSOR_DATATYPES_H_

#include <iostream>
#include <queue>

using namespace std;

class Sensor
{

public:
    Sensor();
    Sensor(int span);
    float AddToRunningAverage(float currentReading);
    float GetRunningAverage();

private:
    float _runningSum;
    int _runningCount;
    int _span;
    float _runningAverage;
    queue<float> _lastx;
};

#endif // SENSOR_DATATYPES_H_
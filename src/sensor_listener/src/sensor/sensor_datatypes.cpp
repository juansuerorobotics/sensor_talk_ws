
#include "sensor/sensor_datatypes.h"

#include <queue>

Sensor::Sensor()
{
}

Sensor::Sensor(int span)
{

    _span = span;
    _runningSum = 0;
    _runningCount = 0;
    _runningAverage = 0;

    std::cout << "Sensor::Sensor: "
              << "_span: " << _span << ", _runningSum: " << _runningSum << ", _runningCount: " << _runningCount << ", _runningAverage " << _runningAverage << std::endl;
}

float Sensor::AddToRunningAverage(float currentReading)
{

    std::cout << "Sensor::AddToRunningAverage: "
              << "currentReading: " << currentReading << std::endl;

    _lastx.push(currentReading);

    if (_runningCount <= _span)
    {
        _runningCount++;
    }
    else
    {
        float lastxpopped = _lastx.front();
        _lastx.pop();
        _runningSum -= lastxpopped;
    }

    _runningSum += currentReading;

    _runningAverage = _runningSum / _runningCount;

    if (_runningCount <= _span)
    {
        _span++;
    }

    std::cout << "Sensor::AddToRunningAverage: "
              << "_runningAverage: " << _runningAverage << std::endl;

    return _runningAverage;
}

float Sensor::GetRunningAverage()
{
    // std::cout << "Sensor::GetRunningAverage: "
    //           << "_runningAverage: " << _runningAverage << std::endl;

    return _runningAverage;
}

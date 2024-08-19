#ifndef _MECANUM_HPP_
#define _MECANUM_HPP_

#include "mbed.h"
#include "math.h"

class Mecanum {

private:

  const double PI = 3.141592653589;

  double _targetSpeed;
  double _targetRotation;
  double _wheel[4];

public:

  Mecanum()
  {};

  void control(double _joyXValue, double _joyYValue, double _turn)
  {
    _targetSpeed    = sqrt( (_joyXValue ^2) + (_joyYValue ^2) );
    _targetRotation = atan2(_joyYValue, _joyXValue) - (PI /4);
    _targetRotation < 0 ? _targetRotation *= -1 : _targetRotation;

    _wheel[0] = sin(_targetRotation) / cos(_targetRotation) * _targetSpeed - _turn;
    _wheel[1] = cos(_targetRotation) / sin(_targetRotation) * _targetSpeed + _turn * -1;
    _wheel[2] = cos(_targetRotation) / sin(_targetRotation) * _targetSpeed - _turn;
    _wheel[3] = sin(_targetRotation) / cos(_targetRotation) * _targetSpeed + _turn * -1;
  }

  double getSpeed(int unit) {
    if(unit < 0 || unit > 3) {
      return 0.0;
    }
    return _wheel[unit];
  }
};

#endif
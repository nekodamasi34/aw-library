#ifndef _MECANUM_HPP_
#define _MECANUM_HPP_

#include "mbed.h"
#include "math.h"

class Mecanum {

private:

  const float PI = 3.1415;

  float _targetSpeed;
  float _targetRotation;
  float _wheel[4];

public:

  Mecanum()
  {};

  void control(float _joyXValue, float _joyYValue, float _turn)
  {
    _targetSpeed    = sqrt( (_joyXValue * _joyXValue) + (_joyYValue * _joyYvalue) );
    _targetRotation = atan2(_joyYValue, _joyXValue) - (PI /4);
    _targetRotation < 0 ? _targetRotation *= -1 : _targetRotation;

    _wheel[0] = sin(_targetRotation) / cos(_targetRotation) * _targetSpeed - _turn;
    _wheel[1] = cos(_targetRotation) / sin(_targetRotation) * _targetSpeed + _turn * -1;
    _wheel[2] = cos(_targetRotation) / sin(_targetRotation) * _targetSpeed - _turn;
    _wheel[3] = sin(_targetRotation) / cos(_targetRotation) * _targetSpeed + _turn * -1;
  }

  float getSpeed(int unit) {
    if(unit < 0 || unit > 3) {
      return 0.0f;
    }
    return _wheel[unit];
  }
};

#endif
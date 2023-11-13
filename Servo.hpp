#ifndef _SERVO_HPP_
#define _SERVO_HPP_

#include "mbed.h"
#include "math.h"
#include <cstdio>

class Servo
{
private:
  int _servo;
  PwmOut servo;
  bool reverse;

public:
  Servo(PinName Servo_pin, bool reverse)
    : servo(Servo_pin), reverse(reverse), _servo(0)
  {
    servo.period(1.0 / 100.0);
    servo.pulsewidth_us(800);
    _servo = 800;
  }

// num分足す 高い値入れたらダメ

  void drive(int num)
  {
    _servo += num;

    if(reverse){
      _servo *= -1;
    }

    if(_servo > (2500)){
      _servo = (2500);
    }else if(_servo < (500)){
      _servo = (500);
    }

    // 500~2500
    servo.pulsewidth_us(_servo);
  }
};

#endif
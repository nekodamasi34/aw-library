#ifndef MECANUM_HPP_
#define MECANUM_HPP_

#include <cmath>
#include <vector>

class Mecanum {
private:
  const float PI = 3.1415;
  float target_speed_;
  float target_rotation_;
  std::vector<float> wheel_speeds_ = {0.0f, 0.0f, 0.0f, 0.0f};

public:
  Mecanum(): target_speed_(0), target_rotation_(0) {
  }

  // 制御ロジックを計算する関数
  void control(float joy_x, float joy_y, float turn) {
    target_speed_ = std::sqrt((joy_x * joy_x) + (joy_y * joy_y));
    target_rotation_ = std::atan2(joy_y, joy_x) - (PI / 4);

    if (target_rotation_ < 0) {
      target_rotation_ *= -1;
    }

    wheel_speeds_[0] =
        std::sin(target_rotation_) / std::cos(target_rotation_) * target_speed_ + turn;
    wheel_speeds_[1] =
        std::cos(target_rotation_) / std::sin(target_rotation_) * target_speed_ * -1 + turn;
    wheel_speeds_[2] =
        std::cos(target_rotation_) / std::sin(target_rotation_) * target_speed_ + turn;
    wheel_speeds_[3] =
        std::sin(target_rotation_) / std::cos(target_rotation_) * target_speed_ * -1 + turn;
  }

  // 指定したホイール速度を取得する関数
  float getSpeed(int unit) {
    if (unit < 0 || unit > 3) {
      return 0.0f;
    }
    return wheel_speeds_[unit];
  }

  // 全ホイール速度を取得する関数
  std::vector<float> getAllSpeeds() const { return wheel_speeds_; }
};

#endif  // MECANUM_HPP_
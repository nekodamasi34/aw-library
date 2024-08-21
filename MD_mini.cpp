#include "MD_mini.hpp"

// Constructor for initializing motor pins and reverse settings
MD_mini::MD_mini(PinName in1_pin, PinName in2_pin, bool reverse1, PinName in3_pin, PinName in4_pin, bool reverse2)
    : in1(in1_pin), in2(in2_pin), reverse1(reverse1), in3(in3_pin), in4(in4_pin), reverse2(reverse2)
{
    in1.period(PWM_FREQUENCY);
    in2.period(PWM_FREQUENCY);
    in3.period(PWM_FREQUENCY);
    in4.period(PWM_FREQUENCY);
}

// Drive only motor 1
void MD_mini::drive_1(float power1)
{
    if (reverse1) power1 *= -1;

    pwm1 = clamp_power(power1);

    in1 = pwm1 > 0 ? pwm1 : 0;
    in2 = pwm1 < 0 ? -pwm1 : 0;
}

// Drive only motor 2
void MD_mini::drive_2(float power2)
{
    if (reverse2) power2 *= -1;

    pwm2 = clamp_power(power2);

    in3 = pwm2 > 0 ? pwm2 : 0;
    in4 = pwm2 < 0 ? -pwm2 : 0;
}

// Drive both motors simultaneously
void MD_mini::drive_both(float power1, float power2)
{
    MD_mini::drive_1(power1);
    MD_mini::drive_2(power2);
}

// Stop both motors
void MD_mini::stop()
{
    in1 = 0;
    in2 = 0;
    in3 = 0;
    in4 = 0;
}

// Run both motors at full speed
void MD_mini::full_speed()
{
    in1 = 1;
    in2 = 1;
    in3 = 1;
    in4 = 1;
}

// Clamps the power value to the maximum allowed power
float MD_mini::clamp_power(float power)
{
    conf_power = power > MAX_POWER ? MAX_POWER : power;
    conf_power = power < -MAX_POWER ? -MAX_POWER : power;
    return (conf_power);
}

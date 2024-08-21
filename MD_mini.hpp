#ifndef _MD_MINI_HPP_
#define _MD_MINI_HPP_

#include "mbed.h"
#include "math.h"

#define PWM_FREQUENCY 0.00005f // PWM 20kHz (1/20000)
#define MAX_POWER 1.0f // モーターの最大出力値

//! MD_mini class for controlling AE-TC78H653FTG motor driver.
/*!
    This class provides functions to control the motor driver in PHASE mode.
    The pins are connected as follows:
    - in1_pin: Motor 1 Forward pin
    - in2_pin: Motor 1 Reverse pin
    - in3_pin: Motor 2 Forward pin
    - in4_pin: Motor 2 Reverse pin

    @author awttenani
*/
class MD_mini
{
public:
    /*!
     * @brief Constructor for initializing motor pins and reverse settings.
     *
     * The pins are connected to the corresponding motor driver pins:
     * - in1_pin: Motor 1 Forward pin
     * - in2_pin: Motor 1 Reverse pin
     * - in3_pin: Motor 2 Forward pin
     * - in4_pin: Motor 2 Reverse pin
     *
     * @param in1_pin Pin for motor 1 forward.
     * @param in2_pin Pin for motor 1 reverse.
     * @param reverse1 Reverse mode for motor 1.
     * @param in3_pin Pin for motor 2 forward.
     * @param in4_pin Pin for motor 2 reverse.
     * @param reverse2 Reverse mode for motor 2.
     */
    MD_mini(PinName in1_pin, PinName in2_pin, bool reverse1, PinName in3_pin, PinName in4_pin, bool reverse2);

    /*!
     * @brief Drive only motor 1.
     *
     * @param power1 Power level for motor 1 (range: -1.0 to 1.0).
     */
    void drive_1(float power1);

    /*!
     * @brief Drive only motor 2.
     *
     * @param power2 Power level for motor 2 (range: -1.0 to 1.0).
     */
    void drive_2(float power2);

    /*!
     * @brief Drive both motors simultaneously.
     *
     * @param power1 Power level for motor 1 (range: -1.0 to 1.0).
     * @param power2 Power level for motor 2 (range: -1.0 to 1.0).
     */
    void drive_both(float power1, float power2);

    /*!
     * @brief Stop both motors.
     */
    void stop();

    /*!
     * @brief Run both motors at full speed.
     */
    void full_speed();

private:
    /*!
     * @brief Clamps the power value to the maximum allowed power.
     *
     * @param power The input power level.
     * @return Clamped power level within the range [0, MAX_POWER].
     */
    float clamp_power(float power);

    //! PWM output pins for motor control.
    PwmOut in1, in2, in3, in4;

    //! Stores the PWM signal values for both motors.
    float pwm1, pwm2;

    //! Stores power signal values.
    float conf_power;

    //! Reverse flags for both motors.
    bool reverse1, reverse2;
};

#endif

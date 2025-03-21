#include "main.h"
#include <cmath>
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value

void driveControl(){
    // drive train control code (for driver control)
    int forward = - master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int lateral = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    forward = 256.0 / (1 + exp(-0.05 * forward)) - 128.0;
    lateral = 256.0 / (1 + exp(-0.05 * lateral)) - 128.0;

    int left = forward - lateral;
    int right = - forward - lateral;

    left1.move_velocity(left * 600.0 / 128.0);
    left2.move_velocity(left * 600.0 / 128.0);
    left3.move_velocity(left * 600.0 / 128.0);
    left4.move_velocity(left * 600.0 / 128.0);
    left5.move_velocity(left * 600.0 / 128.0);

	right1.move_velocity(right * 600.0 / 128.0);
	right2.move_velocity(right * 600.0 / 128.0);
    right3.move_velocity(right * 600.0 / 128.0);
    right4.move_velocity(right * 600.0 / 128.0);
    right5.move_velocity(right * 600.0 / 128.0);
    
}
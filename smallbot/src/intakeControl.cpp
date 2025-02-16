#include "main.h"
#define max_analog 128.0 //maximum analog signal, used for scaling when driver input exceeds said value (max is 128)

int clampDelay = 10;
bool clamp = true;

void intakeControl(){
    // intake control code (for driver control)
    intakeMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    intakeMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    elevatorMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    elevatorMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    armMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    armMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intakeMotorLeft.move_velocity(600);
        intakeMotorRight.move_velocity(-600);

        elevatorMotorLeft.move_velocity(-600 * 1.0);
        elevatorMotorRight.move_velocity(600 * 1.0);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intakeMotorLeft.move_velocity(-600);
        intakeMotorRight.move_velocity(600);

        elevatorMotorLeft.move_velocity(600 * 1.0);
        elevatorMotorRight.move_velocity(-600 * 1.0);
    } else {
        intakeMotorLeft.move_velocity(0);
        intakeMotorRight.move_velocity(0);

        elevatorMotorLeft.move_velocity(0);
        elevatorMotorRight.move_velocity(0);
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        armMotorLeft.move_velocity(-600);
        armMotorRight.move_velocity(600);
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        armMotorLeft.move_velocity(600);
        armMotorRight.move_velocity(-600);
    } else {
        armMotorLeft.move_velocity(0);
        armMotorRight.move_velocity(0);
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A) && clampDelay <= 0){
        clamp = !clamp;
        clampDelay = 10;
    }

    clampDelay = clampDelay - 1;

    if(clamp){
        clampPiston.set_value(true); // extend
    }
    if(!clamp) {
        clampPiston.set_value(false); // retract
    }

}
void intake(){
    // intake one ring (for autonomous)
    intakeMotorLeft.move(-max_analog);
    intakeMotorRight.move(max_analog);

    elevatorMotorLeft.move(max_analog);
    elevatorMotorRight.move(-max_analog);
    pros::delay(1000);
    intakeMotorLeft.move(0);
    intakeMotorRight.move(0);

    elevatorMotorLeft.move(0);
    elevatorMotorRight.move(0);
}
void score(){
    // scores one ring in the goal (for autonomous)
    intakeMotorLeft.move(-max_analog);
    intakeMotorRight.move(max_analog);

    elevatorMotorLeft.move(max_analog);
    elevatorMotorRight.move(-max_analog);
    pros::delay(1000);
    intakeMotorLeft.move(0);
    intakeMotorRight.move(0);

    elevatorMotorLeft.move(0);
    elevatorMotorRight.move(0);
}
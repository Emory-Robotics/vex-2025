#include "main.h"

void gui(){
    while(true){
        pros::lcd::clear_line(0);
        pros::lcd::clear_line(1);
        pros::lcd::clear_line(2);
        pros::lcd::clear_line(3);
        pros::lcd::clear_line(4);
        pros::lcd::clear_line(5);
        pros::lcd::clear_line(6);
        pros::lcd::clear_line(7);

        pros::lcd::print(0, "L1 C: %f, L2 C: %f", left1.get_temperature(), left2.get_temperature());
        pros::lcd::print(1, "L3 C: %f, L4 C: %f", left3.get_temperature(), left4.get_temperature());
        pros::lcd::print(2, "R1 C: %f, R2 C: %f", right1.get_temperature(), right2.get_temperature());
        pros::lcd::print(3, "R3 C: %f, R4 C: %f", right3.get_temperature(), right4.get_temperature());

        //pros::lcd::print(4, "frontLeft W: %i, frontRight W: %i", frontLeft.get_power(), frontRight.get_power());
        //pros::lcd::print(5, "backLeft W: %i, backRight W: %i", backLeft.get_power(), backRight.get_power());

        pros::lcd::print(4, chassis->getState().str().c_str());
        pros::lcd::print(5, " ");

        pros::lcd::print(6, "Battery: %f", pros::battery::get_capacity());
        pros::lcd::print(7, "Controller Battery: %d", master.get_battery_level());

        //master.clear();
        master.print(2, 0, "temp: %f C", (left1.get_temperature() + left2.get_temperature() + left3.get_temperature() + left4.get_temperature() + right1.get_temperature() + right2.get_temperature() + right3.get_temperature() + right4.get_temperature()) / 8.0);
        
        pros::delay(50);
    }
}
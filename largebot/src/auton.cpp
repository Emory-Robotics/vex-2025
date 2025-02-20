#include "main.h"

void skillsAuton(){

}

void auton(){
    // autonomous code
    /*chassis->moveDistance(2_ft);
    pros::delay(200);
    chassis->moveDistance(-2_ft);
    chassis->turnAngle(90_deg);
    pros::delay(200);
    chassis->turnAngle(-90_deg);
    pros::delay(200);
    chassis->turnAngle(45_deg);
    pros::delay(200);
    chassis->turnAngle(-45_deg);
    pros::delay(25000);*/

    chassis->moveDistance(-53_in);
    clampPiston.set_value(true);
    chassis->turnAngle(15_deg);

    chassis->moveDistance(43_in);
    chassis->turnAngle(-155_deg);
    chassis->moveDistance(24_in);

    intake();
    pros::delay(500);
    score();

    chassis->moveDistance(-24_in);
    chassis->turnAngle(210_deg);
    chassis->moveDistance(24_in);

    intake();
    score();

    chassis->moveDistance(-2_in);
    
}
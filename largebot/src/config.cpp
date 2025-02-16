#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor right1(1, pros::E_MOTOR_GEARSET_06);
pros::Motor right2(2, pros::E_MOTOR_GEARSET_06);
pros::Motor right3(3, pros::E_MOTOR_GEARSET_06);
pros::Motor right4(-4, pros::E_MOTOR_GEARSET_06); // bottom middle

pros::Motor left1(5, pros::E_MOTOR_GEARSET_06);
pros::Motor left2(6, pros::E_MOTOR_GEARSET_06);
pros::Motor left3(-7, pros::E_MOTOR_GEARSET_06); // bottom middle
pros::Motor left4(8, pros::E_MOTOR_GEARSET_06);

pros::Motor intakeMotorLeft(11, pros::E_MOTOR_GEARSET_06);
pros::Motor intakeMotorRight(12, pros::E_MOTOR_GEARSET_06);

pros::Motor elevatorMotorLeft(13, pros::E_MOTOR_GEARSET_06);
pros::Motor elevatorMotorRight(14, pros::E_MOTOR_GEARSET_06);

pros::Motor armMotorLeft(15, pros::E_MOTOR_GEARSET_36);
pros::Motor armMotorRight(16, pros::E_MOTOR_GEARSET_36);


pros::ADIDigitalOut clampPiston ('A');

pros::Vision visionSensor(17);

pros::Motor_Group left ({left1, left2, left3, left4});
pros::Motor_Group right ({right1, right2, right3, right4});

std::shared_ptr<OdomChassisController> chassis =
      ChassisControllerBuilder()
        .withMotors({-5, -6, -8, -7}, {1, 2, 3, 4})
        .withDimensions({AbstractMotor::gearset::blue, (60.0 / 60.0)}, {{3.25_in, 14.5_in}, imev5BlueTPR})
        /*.withSensors(
          RotationSensor{16, true}, // Left encoder in V5 port 16 (reversed, the rotation sensors are flipped)
          RotationSensor{6}  // Right encoder in V5 port 6
        )
    		.withOdometry({{4_in, 12.25_in}, quadEncoderTPR})*/
        .withOdometry()
        .withGains(
            {0.001, 0.0000001, 0.00001},
            {0.0015, 0.002, 0.0001},
            {0.001, 0.0000001, 0.00001}
          )
        /*.withDerivativeFilters(
            std::make_unique<AverageFilter<3>>(), // Distance controller filter
            std::make_unique<AverageFilter<3>>(), // Turn controller filter
            std::make_unique<AverageFilter<3>>()  // Angle controller filter
          )*/
        .withLogger(
            std::make_shared<Logger>(
                TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
                "/ser/sout", // Output to the PROS terminal
                Logger::LogLevel::debug // Most verbose log level
            )
          )
        //.withClosedLoopControllerTimeUtil(50, 5, 250_ms)
    		.buildOdometry();

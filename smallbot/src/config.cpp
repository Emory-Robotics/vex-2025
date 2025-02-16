#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor left1(1, pros::E_MOTOR_GEARSET_06);
pros::Motor left2(-3, pros::E_MOTOR_GEARSET_06);
pros::Motor left3(5, pros::E_MOTOR_GEARSET_06);

pros::Motor right1(2, pros::E_MOTOR_GEARSET_06);
pros::Motor right2(4, pros::E_MOTOR_GEARSET_06);
pros::Motor right3(-6, pros::E_MOTOR_GEARSET_06);

pros::Motor intakeMotorLeft(-11, pros::E_MOTOR_GEARSET_06);
pros::Motor intakeMotorRight(-12, pros::E_MOTOR_GEARSET_06);

pros::Motor elevatorMotorLeft(7, pros::E_MOTOR_GEARSET_06);
pros::Motor elevatorMotorRight(8, pros::E_MOTOR_GEARSET_06);

pros::Motor armMotorLeft(13, pros::E_MOTOR_GEARSET_36);
pros::Motor armMotorRight(14, pros::E_MOTOR_GEARSET_36);


pros::ADIDigitalOut clampPiston ('A');

pros::Vision visionSensor(11);

std::shared_ptr<OdomChassisController> chassis =
      ChassisControllerBuilder()
        .withMotors({-1, -3}, {2, 4})
        // Blue gearset, 4 in in wheel diam, 26 cm in wheel track
        .withDimensions({AbstractMotor::gearset::blue, (84.0 / 36.0)}, {{4_in, 13.5_in}, imev5BlueTPR})
        /*.withSensors(
          RotationSensor{16, true}, // Left encoder in V5 port 16 (reversed, the rotation sensors are flipped)
          RotationSensor{6}  // Right encoder in V5 port 6
        )
    		.withOdometry({{4_in, 12.25_in}, quadEncoderTPR})*/
        .withOdometry()
        .withGains(
            {0.001, 0.0000001, 0.00001},
            {0.0015, 0.000001, 0.00002},
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

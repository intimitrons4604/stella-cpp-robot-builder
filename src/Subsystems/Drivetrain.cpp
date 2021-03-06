// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drivetrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/JoystickDrive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    motorLeft1 = RobotMap::drivetrainMotorLeft1;
    motorLeft2 = RobotMap::drivetrainMotorLeft2;
    motorRight1 = RobotMap::drivetrainMotorRight1;
    motorRight2 = RobotMap::drivetrainMotorRight2;
    robotDrive = RobotMap::drivetrainRobotDrive;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new JoystickDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::Drive(float straightValue, float turnValue, bool turbo) {
    /*
     * Invert turbo setting to get squaredInputs value
     * Squaring the inputs results in a power output which is less than
     * the input value, except at -1, 0, and 1 - where they are equal.
     * Graph f(x) = x^2, g(x) = -(x^2), and h(x) = x to see this visually.
     */
    robotDrive->ArcadeDrive(straightValue, turnValue, !turbo);
}

void Drivetrain::StopMotors() {
    robotDrive->StopMotor();
}

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RotateInPlace.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RotateInPlace::RotateInPlace(bool counterClockWise, double rotationRate): Command() {
    m_counterClockWise = counterClockWise;
    m_rotationRate = rotationRate;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RotateInPlace::Initialize() {
    drivetrain = Robot::drivetrain;
}

// Called repeatedly when this Command is scheduled to run
void RotateInPlace::Execute() {
    // Protect us from negative rotationRates
    // Transform to a turnvalue - positive is CCW, negitave is CW rotation
    float turnValue = m_counterClockWise ? std::abs(m_rotationRate) : - std::abs(m_rotationRate);

    // Turn only, use turbo so desired rotationRate and motor output correspond exactly
    drivetrain->Drive(0, turnValue, true);
}

// Make this return true when this Command no longer needs to run execute()
bool RotateInPlace::IsFinished() {
    // This command is fired while a button is held
    // The command is constantly rescheduled while the button is pressed
    // Note that motor safety will stop the rotation if the command is not rescheduled
    return true;
}

// Called once after isFinished returns true
void RotateInPlace::End() {
    drivetrain->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateInPlace::Interrupted() {
    End();
}

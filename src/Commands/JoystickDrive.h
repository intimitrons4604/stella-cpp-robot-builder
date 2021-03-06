// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef JOYSTICKDRIVE_H
#define JOYSTICKDRIVE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Drivetrain;

/**
 *
 *
 * @author ExampleAuthor
 */
class JoystickDrive: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	JoystickDrive();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	static constexpr float DEFAULT_DEADZONE = 0.2;

	// Left stick, Y-axis on Xbox controller
	static constexpr uint32_t STRAIGHT_AXIS_NUMBER = 1;
	// Left stick, X-axis on Xbox controller
	static constexpr uint32_t TURN_AXIS_NUMBER = 0;
	// Right bumper on Xbox controller (RB)
	static constexpr uint32_t TURBO_BUTTON_NUMBER = 6;

	std::shared_ptr<Drivetrain> drivetrain;
	std::shared_ptr<Joystick> driveJoystick;

	/**
	 * Apply an axial deadzone filter to a given input value.
	 *
	 * Assumes a zero-centered axis input value, meaning that at rest, the input value
	 * is zero.
	 *
	 * @param input The axis input value to apply the deadzone to
	 * @param size The size of the deadzone. If not provided, the default deadzone is used.
	 * @return If abs(input) < size, returns 0. Otherwise, returns input
	 */
	static float applyAxialDeadzone(float input, float size = DEFAULT_DEADZONE);
};

#endif

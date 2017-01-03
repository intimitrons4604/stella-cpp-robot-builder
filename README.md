# What is this?
This repository contains a command-based robot implementation to *drive* Stella. The code outline was generated using [RobotBuilder](https://wpilib.screenstepslive.com/s/4485/m/26402). The required RobotBuilder file is in this repository, named `StellaCppRobotBuilder.yaml`. Open it with RobotBuilder and check it out.

# WARNING - Untested Code
**This code has never been run on physical hardware or a simulator - it is untested.** As the code is untested, no guarantees are made regarding the safety of persons or property in Stella's vicinity while the code is running.

If you're feeling brave, try running it in a very large area or with the chassis on a stand. When you are confident it works, let Stella roam free.

# Autonomous Mode
In autonomous mode, Stella will continuously drive straight forward with the motors at half power. This is done by the `AutonomousDriveStraight` command, with a `speed` parameter of `0.5`.

# Teleoperated Mode
In teleoperated mode, you can drive Stella using the left stick. The y-axis controls straight motion, and the x-axis controls turning. There is an axial deadzone applied to each axes' input values. The turbo button is the right bumper (labelled RB). This driving is performed by the `JoystickDrive` command - the default command for the Drivetrain subsystem.

If you hold down the X button, Stella will rotate counter-clockwise in place with the motors at one quarter power as long as you are holding the button. If you hold down the B button, Stella will do the same thing, this time rotating clockwise. The rotation is performed by the `RotateInPlace` command, with differing values for the `counterClockWise` parameter, and the same value for the `rotationRate` parameter.

If you're feeling mischievous and try holding both, *I believe* that you'll either get some weird quivering back and forth rotation, or always end up with counter-clockwise rotation. Try changing the order you push the two buttons in. Let me know what you find out.

If you want to be mischievous twice in one day, try seeing if you can still drive with the joysticks while holding one of X or B.

# SmartDashboard and LiveWindow
You should be able to do some SmartDashboard and LiveWindow related things with this code, since the RobotBuilder sets it up in many places. At this point, I haven't looked into this a whole lot.
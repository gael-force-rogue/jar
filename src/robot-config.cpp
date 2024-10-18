#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain Brain;

// The motor constructor takes motors as (port, ratio, reversed), so for example
// motor LeftFront = motor(PORT1, ratio6_1, false);

// Add your devices below, and don't forget to do the same in robot-config.h:
motor Left1(vex::PORT2, true);
motor Left2(vex::PORT8, false);
motor Left3(vex::PORT6, true);
motor Right1(vex::PORT9, false);
motor Right2(vex::PORT15, true);
motor Right3(vex::PORT11, false);

motor Intake(vex::PORT16, true);
motor Lift(vex::PORT7, false);

Piston Clamp(pneumatics(Brain.ThreeWirePort.H), false);
Piston Hang(pneumatics(Brain.ThreeWirePort.B), false);
Piston Knocker(pneumatics(Brain.ThreeWirePort.A), false);

#ifndef CONFIG_H
#define CONFIG_H

// Devices
#define MOTOR_LEFT_1 vex::motor(vex::PORT2, true)
#define MOTOR_LEFT_2 vex::motor(vex::PORT8, false)
#define MOTOR_LEFT_3 vex::motor(vex::PORT6, true)
#define MOTOR_RIGHT_1 vex::motor(vex::PORT9, false)
#define MOTOR_RIGHT_2 vex::motor(vex::PORT15, true)
#define MOTOR_RIGHT_3 vex::motor(vex::PORT11, false)

#define MOTOR_INTAKE vex::motor(vex::PORT16, true)
#define MOTOR_LIFT vex::motor(vex::PORT7, false)
#define DISTANCE_SENSOR vex::PORT5

#define INERTIAL_SENSOR vex::PORT12

// PID Constants
#define DRIVE_PID_kP 0.6
#define DRIVE_PID_kI 0.0
#define DRIVE_PID_kD 8.0
#define DRIVE_PID_ACCURACY 1

// no clmap kP: 1.0

#define HEADING_PID_kP 30
#define HEADING_PID_kI 0.0
#define HEADING_PID_kD 0.0
#define HEADING_PID_ACCURACY 0.5

#endif  // CONFIG_H

void vexcodeInit(void) {
    // nothing to initialize
}
#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain Brain;

// The motor constructor takes motors as (port, ratio, reversed), so for example
// motor LeftFront = motor(PORT1, ratio6_1, false);

// Add your devices below, and don't forget to do the same in robot-config.h:
motor Left1(PORT15, ratio18_1, true);
motor Left2(PORT9, ratio18_1, false);
motor Left3(PORT13, ratio18_1, true);
motor Right1(PORT6, ratio18_1, true);
motor Right2(PORT12, ratio18_1, false);
motor Right3(PORT10, ratio18_1, true);

motor Intake(PORT11, ratio18_1, true);
motor Lift(PORT3, ratio18_1, false);

Piston Clamp(pneumatics(Brain.ThreeWirePort.H), false);
Piston Hang(pneumatics(Brain.ThreeWirePort.B), false);
Piston Knocker(pneumatics(Brain.ThreeWirePort.A), false);

void vexcodeInit(void) {
    // nothing to initialize
}
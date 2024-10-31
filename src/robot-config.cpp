#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain Brain;
controller Controller;

motor Left1(vex::PORT2, true);
motor Left2(vex::PORT8, false);
motor Left3(vex::PORT6, true);
motor Right1(vex::PORT9, false);
motor Right2(vex::PORT15, true);
motor Right3(vex::PORT11, false);

IntakeMotor Intake(vex::PORT16, true);
void LiftMotor::score() {
    this->spinToPosition(100, deg, true);
    Intake.forward();
    this->spinToPosition(200, deg, true);
    this->returnToDefaultPosition(true);
};
LiftMotor Lift(vex::PORT7, false);

Piston Clamp(pneumatics(Brain.ThreeWirePort.H), false);
Piston Hang(pneumatics(Brain.ThreeWirePort.B), false);
Piston Knocker(pneumatics(Brain.ThreeWirePort.A), false);

ColorSensor colorSensor(vex::PORT10);

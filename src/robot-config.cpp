#include <iostream>

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

const bool isRed = AUTON & RED;
const bool isBlue = AUTON & BLUE;
const bool isSkills = AUTON & SKILLS;

float normalize360(float angle) {
    while (angle >= 360) {
        angle -= 360;
    }
    while (angle <= -360) {
        angle += 360;
    }
    return angle;
};

bool Intake::launchRingIfNeeded() {
    auto rgb = this->colorSensor.getRgb();
    if (((isRed || isSkills) && rgb.blue > 200) || (isBlue && rgb.red > 200)) {
        float originalVelocity = this->velocity(pct);
        this->forward(100);
        wait(600, msec);
        this->stop();
        wait(600, msec);
        this->forward(originalVelocity);
        return true;
    };
    return false;
};

void Intake::search() {
    intake.state = SEARCHING;
    while (intake.state == SEARCHING) {
        auto rgb = intake.colorSensor.getRgb();

        std::cout << rgb.red << std::endl;

        if (rgb.red > 200 || rgb.blue > 200) {
            intake.stop();
            intake.state = OFF;
        }

        wait(20, msec);
    };
};

void LiftMotor::score() {
    this->spinToRelativePosition(100, true);
    intake.forward();
    this->spinToRelativePosition(200, true);
    this->returnToDefaultPosition(true);
    intake.stop();
};

Intake intake(vex::PORT18, true, vex::PORT10);
LiftMotor Lift(vex::PORT7, false);

Piston Clamp(pneumatics(Brain.ThreeWirePort.H), false);
Piston Hang(pneumatics(Brain.ThreeWirePort.B), false);
Piston Knocker(pneumatics(Brain.ThreeWirePort.A), false);

void intakeSearchingThreadF() {
    intake.colorSensor.setLightPower(100);

    const float startingSystemTime = vex::timer::system();

    while (1) {
        // if (intake.launchRingIfNeeded()) {
        //     continue;
        // }

        if (!chassis.Gyro.installed()) {
            std::cout << "IMU Not Installed: " << (vex::timer::system() - startingSystemTime) / 1000 << std::endl;
        };

        if (intake.state == SEARCHING) {
            intake.colorSensor.setLightPower(100);
            intake.setStopping(hold);
            intake.forward(55);
            Lift.returnToDefaultPosition(true);

            intake.search();

            intake.colorSensor.setLightPower(100);
        }

        wait(10, msec);
    }
};
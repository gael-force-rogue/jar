#include <iostream>

#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */
void default_constants() {
    // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
    chassis.set_drive_constants(10, 2, 0, 10, 0);
    chassis.set_heading_constants(6, 1.2, 0, 1, 0);
    chassis.set_turn_constants(7, .2, 0, 1.3, 0);
    chassis.set_swing_constants(12, 2, .0, 5, 15);

    // Each exit condition set is in the form of (settle_error, settle_time, timeout).
    chassis.set_drive_exit_conditions(1.5, 200, 3000);
    chassis.set_turn_exit_conditions(0.5, 150, 700);
    chassis.set_swing_exit_conditions(1, 300, 1000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */
void odom_constants() {
    default_constants();
    chassis.heading_max_voltage = 10;
    chassis.drive_max_voltage = 8;
    chassis.drive_settle_error = 3;
    chassis.boomerang_lead = .5;
    chassis.drive_min_voltage = 0;
}

void delayedIntakeThreadF() {
    wait(250, msec);
    Intake.forward();
};

void intakePulseReverseThreadF() {
    Intake.backward();

    wait(1000, msec);
    Intake.forward();
};

void intakeColorSortThreadF() {
    while (true) {
        if (Intake.velocity(pct) > 20 && colorSensor.ringDetected()) {
            Intake.stop();
            wait(100, msec);
            Intake.forward();
            do {
                wait(20, msec);
            } while (colorSensor.ringDetected());
        };

        wait(20, msec);
    }
};

void runAuton(Auton auton) {
    default_constants();
    chassis.set_coordinates(0, 0, 0);
    Intake.resetPosition();
    Lift.resetPosition();
    Lift.setVelocity(100, percent);

    // vex::thread intakeColorSortThread(intakeColorSortThreadF);

    vex::timer autonTimer;

    switch (auton) {
        case RED_AWP:
            red_awp();
            break;
        case BLUE_AWP:
            blue_awp();
            break;
        case RED_ELIMS:
            red_elims();
            break;
        case BLUE_ELIMS:
            blue_elims();
            break;
        case SKILLS:
            skills();
            break;
        case NPC:
            npc();
            break;
    };

    std::cout << "Auton Took: " << autonTimer.time() << "ms" << std::endl;
    autonTimer.~timer();
};
#include <iostream>

#include "vex.h"

void setDefaultConstants() {
    if (AUTON != SKILLS) {
        // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
        chassis.set_drive_constants(10, 2, 0, 10, 0);
        chassis.set_heading_constants(6, 1.2, 0, 1, 0);
        chassis.set_turn_constants(7, .2, 0, 1.3, 0);
        chassis.set_swing_constants(12, 2, .0, 5, 15);

        // chassis.drive_min_voltage = 2;
        chassis.swing_max_voltage = 5;
        chassis.turn_max_voltage = 7;

        // Each exit condition set is in the form of (settle_error, settle_time, timeout).
        chassis.set_drive_exit_conditions(1.5, 200, 2500);
        chassis.set_turn_exit_conditions(1, 150, 1000);
        chassis.set_swing_exit_conditions(1, 300, 600);
    } else {
        // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
        chassis.set_drive_constants(12, 2, 0, 10, 0);
        chassis.set_heading_constants(6, 1.2, 0, 1, 0);
        chassis.set_turn_constants(7, .2, 0, 1.3, 0);
        chassis.set_swing_constants(12, 2, .0, 5, 15);

        // chassis.drive_min_voltage = 2;
        chassis.swing_max_voltage = 5;
        chassis.turn_max_voltage = 7;

        // Each exit condition set is in the form of (settle_error, settle_time, timeout).
        chassis.set_drive_exit_conditions(1.5, 200, 4000);
        chassis.set_turn_exit_conditions(1.3, 150, 1300);
        chassis.set_swing_exit_conditions(1, 300, 1500);
    };

    if (AUTON == RED_MOGORUSH || AUTON == BLUE_MOGORUSH) {
        chassis.set_turn_exit_conditions(3, 100, 300);
    }
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */
void setOdometryConstants() {
    setDefaultConstants();
    chassis.heading_max_voltage = 10;
    chassis.drive_max_voltage = 7;
    chassis.drive_settle_error = 3;
    chassis.boomerang_lead = .5;
    chassis.drive_min_voltage = 0;
}

void delayedIntakeStartThreadF() {
    wait(250, msec);
    intake.forward();
};

void intakePulseReverseThreadF() {
    intake.backward();
    wait(750, msec);
    intake.forward();
};

void delayedIntakeStopThreadF() {
    wait(800, msec);
    intake.stop();
};

void shortDelayedIntakeStopThreadF() {
    wait(350, msec);
    intake.stop();
};

void intakeBurstF() {
    intake.forward();
    wait(925, msec);
    intake.stop();
};

void disconnectThreadF() {
    while (true) {
        if (!chassis.Gyro.installed()) {
            std::cout << "IMU Not Installed" << std::endl;
        };
        if (!intake.installed()) {
            std::cout << "Intake Not Installed" << std::endl;
        };
        wait(10, msec);
    };
};

void liftToggleThreadF() {
    Lift.cycle();
}
void runAuton(Auton auton) {
    setDefaultConstants();
    chassis.set_coordinates(0, 0, 0);

    intake.resetPosition();
    intake.setVelocity(100, percent);
    intake.setStopping(coast);

    Lift.resetPosition();
    Lift.setVelocity(100, percent);

    // Lift.returnToDefaultPosition(false);

    // vex::thread intakeSearchingThread(intakeSearchingThreadF);
    vex::thread disconnectThread(disconnectThreadF);

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
        case RED_MOGORUSH:
            red_mogorush();
            break;
        case BLUE_MOGORUSH:
            blue_mogorush();
            break;
        case SKILLS:
            skills();
            break;
        case NPC:
            npc();
            break;
    };
    chassis.drive_stop(hold);

    std::cout << "Auton Took: " << autonTimer.time() << "ms" << std::endl;
    std::cout << "Intake Temp: " << intake.temperature(celsius) << std::endl;
    std::cout << "LeftChassis Temp: " << Left1.temperature(celsius) << ", " << Left2.temperature(celsius) << ", " << Left3.temperature(celsius) << std::endl;
    std::cout << "RightChassis Temp: " << Right1.temperature(celsius) << ", " << Left2.temperature(celsius) << ", " << Left3.temperature(celsius) << std::endl;

    autonTimer.~timer();

    // wait(1000, msec);
    // Clamp.toggle();

    // std::cout << "WARNING: AUTO UNCLAMP IS ON" << std::endl;
};
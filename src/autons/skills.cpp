#include <iostream>

#include "vex.h"

#define WRAP_ODOM(expr)                                                                                                                                    \
    std::cout << "Start: (" << chassis.get_X_position() << ", " << chassis.get_Y_position() << ", " << chassis.get_absolute_heading() << ")" << std::endl; \
    expr;                                                                                                                                                  \
    std::cout << "End: (" << chassis.get_X_position() << ", " << chassis.get_Y_position() << ", " << chassis.get_absolute_heading() << ")" << std::endl;

void skillsIntakeSearchThreadF() {
    intake.search();
}

void printPosition() {
    std::cout << "X: " << chassis.odom.X_position << std::endl;
    std::cout << "Y: " << chassis.odom.Y_position << std::endl;
    std::cout << "Theta: " << chassis.odom.orientation_deg << std::endl;
}

void skills() {
    chassis.drive_stop(hold);
    intake.setStopping(coast);
    Lift.setStopping(hold);
    intake.stop();
    Lift.stop();
    wait(500, msec);

    vex::thread intakePulseReverseThread;
    vex::thread delayedIntakeStopThread;
    vex::thread intakeBurst;

    // Alliance Stake
    intake.forward();
    wait(900, msec);
    intake.stop();

    // Mogo
    chassis.drive_distance(4.62);
    Clamp.toggle();
    chassis.turn_to_angle(-90);

    float midpointX = chassis.odom.X_position,
          midpointY = chassis.odom.Y_position,
          midpointTheta = chassis.odom.orientation_deg;
    printPosition();

    chassis.drive_distance(-6.75);
    Clamp.toggle();

    // Ring 1
    chassis.drive_distance(-3);
    chassis.turn_to_angle(0);
    intake.spin(forward);
    chassis.drive_distance(6);
    wait(200, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 2
    wait(300, msec);
    chassis.turn_to_angle(50);
    intake.spin(forward);
    chassis.drive_distance(13);
    wait(1000, msec);

    // Rings 3,4,5
    chassis.drive_distance(-3.2);
    intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);
    wait(600, msec);
    chassis.set_turn_exit_conditions(0.5, 150, 1500);
    chassis.turn_to_angle(180);
    setDefaultConstants();
    chassis.drive_max_voltage = 4;
    chassis.drive_distance(16.3);
    setDefaultConstants();
    wait(1000, msec);
    intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);

    // Ring 6
    chassis.drive_distance(-8);
    chassis.turn_to_angle(140);
    intake.forward();
    chassis.drive_distance(4);
    wait(750, msec);

    // Drop Mogo
    chassis.turn_to_angle(-10);
    intake.backward();
    Clamp.toggle();
    chassis.drive_distance(-5.5);

    // Travel to 2nd Mogo
    setDefaultConstants();
    chassis.turn_to_angle(-45);
    chassis.drive_distance(3);
    intake.stop();
    chassis.turn_to_point(midpointX, midpointY - 1.25);
    chassis.set_heading_constants(3, 1.3, 0, 2.2, 0);
    chassis.drive_max_voltage = 8;
    chassis.drive_to_pose(midpointX, midpointY - 1.25, midpointTheta);
    chassis.turn_to_angle(-90);
    printPosition();
    chassis.set_turn_exit_conditions(1, 250, 1300);
    chassis.turn_to_angle(90);
    setDefaultConstants();

    // Clamp 2nd Mogo
    chassis.drive_distance(-5.75);
    wait(100, msec);
    Clamp.toggle();

    // Ring 1
    chassis.drive_distance(-1.6);
    chassis.turn_to_angle(0);
    intake.spin(forward);
    chassis.drive_distance(6.3);
    wait(500, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 2
    wait(500, msec);
    // chassis.set_swing_constants(5, 2, .0, 5, 15);
    chassis.turn_to_angle(-48);
    intake.spin(forward);
    chassis.drive_distance(13);
    wait(750, msec);

    // Rings 3,4,5
    chassis.drive_distance(-3);
    intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);
    wait(200, msec);
    chassis.set_turn_exit_conditions(0.5, 300, 1700);
    chassis.turn_to_angle(183);
    chassis.drive_max_voltage = 4;
    chassis.drive_distance(16.5);
    setDefaultConstants();
    wait(750, msec);

    // Ring 6
    intake.stop();
    chassis.drive_distance(-8);
    chassis.turn_to_angle(-137);
    intake.forward();
    chassis.drive_distance(5);
    wait(1000, msec);

    // Drop Mogo
    chassis.turn_to_angle(20);
    intake.backward();
    Clamp.toggle();
    chassis.drive_distance(-5);
    intake.stop();

    // Travel To Hang
    chassis.turn_to_angle(60);
    chassis.drive_distance(4);
    chassis.turn_to_angle(-135);
    Hang.toggle();
    chassis.drive_distance(-22);
    wait(1000, msec);
    chassis.drive_distance(8);
    chassis.turn_to_angle(-135);
    chassis.drive_distance(-13);
};

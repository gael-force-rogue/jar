#include <iostream>

#include "vex.h"

void skills() {
    Intake.forward();
    wait(600, msec);
    Intake.stop();

    // Goto Mogo
    chassis.drive_distance(4.75);
    chassis.turn_to_angle(-90);
    chassis.drive_distance(-5.5);
    Clamp.toggle();
    chassis.drive_distance(-3);
    chassis.turn_to_angle(0);
    Intake.forward();
    chassis.drive_distance(7);
    wait(600, msec);
    Intake.stop();
    std::cout << chassis.get_X_position() << ", " << chassis.get_Y_position() << std::endl;

    chassis.drive_to_pose(20, 35, 0);
    std::cout << chassis.get_X_position() << ", " << chassis.get_Y_position() << ", " << chassis.get_absolute_heading() << std::endl;

    wait(1000, msec);
    Clamp.toggle();
};
#include <iostream>

#include "vex.h"

#define WRAP_ODOM(expr)                                                                                                                                    \
    std::cout << "Start: (" << chassis.get_X_position() << ", " << chassis.get_Y_position() << ", " << chassis.get_absolute_heading() << ")" << std::endl; \
    expr;                                                                                                                                                  \
    std::cout << "End: (" << chassis.get_X_position() << ", " << chassis.get_Y_position() << ", " << chassis.get_absolute_heading() << ")" << std::endl;

void skillsIntakeSearchThreadF() {
    intake.search();
}

void skills() {
    intake.forward();
    wait(600, msec);
    intake.stop();
    Lift.returnToDefaultPosition(false);

    // Mogo
    chassis.drive_distance(4.75);
    chassis.drive_stop(hold);
    chassis.turn_to_angle(-90);
    chassis.drive_stop(hold);
    chassis.drive_distance(-5.6);
    Clamp.toggle();

    // Ring
    chassis.drive_distance(-3);
    chassis.turn_to_angle(0);
    intake.forward();
    chassis.drive_distance(6);
    chassis.left_swing_to_angle(45);

    // 2nd Ring
    setOdometryConstants();
    chassis.set_heading_constants(4, 3, 0, 3, 0);
    chassis.drive_to_point(17.9, 23);
    setDefaultConstants();
    // chassis.drive_distance(-1);
    chassis.turn_to_angle(0);
    chassis.drive_distance(7);

    // Neutral Stake (3rd Ring)
    wait(100, msec);
    chassis.turn_to_angle(180);
    WRAP_ODOM(chassis.drive_distance(6.5));
    chassis.turn_settle_time = 600;
    chassis.turn_to_angle(90);
    chassis.turn_settle_time = 150;
    vex::thread skillsIntakeSearchThread(skillsIntakeSearchThreadF);
    chassis.drive_distance(6.75);

    Lift.spinToRelativePosition(0, false);
    intake.forward(50);

    Lift.score();
};
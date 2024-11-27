#include "vex.h"

void blue_mogorush() {
    chassis.turn_settle_time = 100;
    chassis.drive_distance(10);
    Knocker.toggle();
    chassis.turn_to_angle(53);
    chassis.drive_distance(4);
    wait(300, msec);
    Knocker.toggle();
    wait(300, msec);
    chassis.drive_distance(-5);
    chassis.set_turn_exit_conditions(1, 200, 1000);
    chassis.turn_to_angle(25);
    Knocker.toggle();
    chassis.drive_distance(2.5);
    Lift.spinToRelativePosition(340, false);
    wait(3000, msec);
    chassis.turn_to_angle(0);
    chassis.drive_distance(-5);
    Knocker.toggle();
};
#include <iostream>

#include "vex.h"

void blue_awp() {
    Lift.spinToPosition(-20, deg, false);

    chassis.drive_distance(3.25);
    chassis.right_swing_to_angle(-90);
    chassis.left_swing_to_angle(-93);
    chassis.drive_distance(-1.65);

    vex::thread delayedIntakeStartThread(delayedIntakeStartThreadF);
    Lift.spinToPosition(70, deg, true);
    Lift.spinToPosition(250, deg, true);
    Lift.spinToPosition(70, deg, true);
    Lift.spinToPosition(-20, deg, false);
    intake.stop();

    // Go to & Pick up Mogo
    chassis.turn_to_angle(-45);
    chassis.drive_settle_time = 250;
    chassis.drive_distance(-11.4);
    chassis.drive_settle_time = 200;
    Clamp.toggle();
    vex::thread intakePulseReverse(intakePulseReverseThreadF);
    chassis.drive_distance(-2.75);

    // Get 1st Ring (standalone)
    chassis.turn_timeout = 1500;
    chassis.turn_to_angle(-180);
    chassis.turn_timeout = 750;
    intake.forward();
    chassis.drive_distance(7);
    wait(100, msec);

    // Align for 2nd ring (stack)
    chassis.turn_to_angle(-275);
    chassis.drive_distance(5.4);
    wait(300, msec);
    chassis.left_swing_to_angle(-280);
    intake.stop();
    chassis.drive_distance(-5);

    // Get 3rd Ring (stack)
    intake.forward();
    chassis.turn_to_angle(-250);
    chassis.drive_distance(5.5);
    wait(300, msec);

    // Come back and aim for ladder
    chassis.drive_distance(-3.25);
    chassis.turn_to_angle(15);
    // Go to ladder
    Lift.spinToPosition(215, deg, false);

    intake.stop();
    chassis.drive_distance(8.5);
    chassis.drive_stop(hold);
};
#include <iostream>

#include "vex.h"

void blue_awp() {
    Lift.spinToPosition(-20, deg, false);

    chassis.drive_distance(3.25);
    chassis.right_swing_to_angle(-90);
    chassis.left_swing_to_angle(-93);
    chassis.drive_distance(-1.6);

    vex::thread delayedIntakeThread(delayedIntakeThreadF);
    Lift.spinToPosition(70, deg, true);
    Lift.spinToPosition(250, deg, true);
    Lift.spinToPosition(70, deg, true);
    Lift.spinToPosition(-20, deg, false);
    // chassis.drive_distance(-0.5);
    Intake.stop();

    // Go to & Pick up Mogo
    chassis.turn_to_angle(-48);
    chassis.drive_settle_time = 250;
    chassis.drive_distance(-10.25);
    chassis.drive_settle_time = 200;
    Clamp.toggle();
    vex::thread intakePulseReverse(intakePulseReverseThreadF);
    chassis.drive_distance(-2.75);

    // Get 1st Ring (standalone)
    chassis.turn_to_angle(-183);
    Intake.forward();
    chassis.drive_distance(7);
    wait(100, msec);

    // Align for 2nd ring (stack)
    chassis.turn_to_angle(-275);
    chassis.drive_distance(4.75);
    wait(300, msec);
    chassis.left_swing_to_angle(-280);
    Intake.stop();
    chassis.drive_distance(-5);

    // Get 3rd Ring (stack)
    Intake.forward();
    chassis.turn_to_angle(-250);
    chassis.drive_distance(5.75);
    wait(300, msec);

    // Come back and aim for ladder
    chassis.drive_distance(-3.25);
    chassis.turn_to_angle(15);
    // Go to ladder
    Lift.spinToPosition(200, deg, false);

    Intake.stop();
    chassis.drive_distance(10);
    chassis.drive_stop(hold);
};
#include <iostream>

#include "vex.h"

void red_awp() {
    vex::thread delayedIntakeStopThread;

    // Score Alliance
    Lift.resetPosition();
    chassis.turn_to_angle(52);
    chassis.drive_distance(2.6);
    Lift.spinToRelativePosition(320, false);

    // Clamp
    wait(600, msec);
    chassis.drive_distance(-1.85);
    chassis.turn_to_angle(75);
    Lift.stop(coast);
    chassis.drive_distance(-10.5);
    Clamp.toggle();

    // 1st Ring
    chassis.turn_to_angle(180);
    intake.forward();
    chassis.drive_distance(6);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // 2nd Ring
    chassis.turn_to_angle(262);
    intake.forward();
    chassis.drive_distance(5);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);
    wait(300, msec);

    // 3rd Ring
    chassis.drive_distance(-4);
    chassis.turn_to_angle(230);
    chassis.drive_distance(3.7);
    intake.forward();
    chassis.left_swing_to_angle(262);
    chassis.drive_distance(2);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);
    wait(300, msec);

    // Ladder
    chassis.drive_distance(-3);
    chassis.turn_to_angle(0);
    Lift.spinToPosition(240, deg, false);
    chassis.drive_distance(10.5);
    Lift.stop(coast);
    intake.stop(coast);
};

// void red_awp() {
//     Lift.returnToDefaultPosition(false);

//     chassis.drive_distance(3.25);
//     chassis.left_swing_to_angle(90);
//     chassis.right_swing_to_angle(92);
//     chassis.drive_distance(-1.45);

//     vex::thread delayedIntake(delayedIntakeStartThreadF);
//     Lift.spinToPosition(70, deg, true);
//     Lift.spinToPosition(248, deg, true);
//     Lift.spinToPosition(70, deg, true);
//     Lift.spinToPosition(-20, deg, false);
//     intake.stop();

//     // Go to & Pick up Mogo
//     chassis.turn_to_angle(48);
//     chassis.drive_settle_time = 250;
//     chassis.drive_distance(-10.9);
//     chassis.drive_settle_time = 200;
//     Clamp.toggle();
//     vex::thread intakePulseReverse(intakePulseReverseThreadF);
//     chassis.drive_distance(-2.75);

//     // Get 1st Ring (standalone)
//     // chassis.turn_timeout = 2000;
//     // chassis.turn_max_voltage = 5;
//     chassis.turn_to_angle(177);
//     chassis.drive_stop(hold);
//     // chassis.turn_max_voltage = 7;
//     // chassis.turn_timeout = 1000;
//     intake.forward();
//     wait(200, msec);
//     chassis.drive_distance(7.3);
//     // vex::thread shortDelayedIntakeStopThread(shortDelayedIntakeStopThreadF);
//     wait(400, msec);

//     // Align for 2nd ring (stack)
//     chassis.turn_to_angle(-84);
//     intake.forward();
//     chassis.drive_distance(4.5);
//     wait(200, msec);
//     chassis.right_swing_to_angle(-80);
//     intake.stop();
//     chassis.drive_distance(-5);

//     // Get 3rd Ring (stack)
//     chassis.turn_to_angle(-110);
//     intake.forward();
//     chassis.drive_distance(5.3);
//     wait(100, msec);

//     // Come back and aim for ladder
//     chassis.drive_distance(-3.5);
//     return;
//     intake.stop();
//     chassis.turn_to_angle(-15);
//     // Go to ladder
//     Lift.spinToPosition(180, deg, false);
//     Lift.spinToPosition(215, deg, false);
//     chassis.drive_distance(10.5);
//     chassis.drive_stop(hold);
// };
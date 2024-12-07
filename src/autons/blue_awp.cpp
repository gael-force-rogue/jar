#include <iostream>

#include "vex.h"

void blue_awp() {
    vex::thread delayedIntakeStopThread;

    // Score Alliance
    Lift.resetPosition();
    chassis.turn_to_angle(-53.5);
    chassis.drive_distance(3);
    Lift.spinToRelativePosition(330, false);

    // Clamp
    wait(600, msec);
    chassis.drive_distance(-2);
    chassis.turn_to_angle(-75);
    Lift.stop(coast);
    chassis.drive_max_voltage = 10;
    chassis.drive_kd = 17;
    chassis.drive_distance(-10);
    Clamp.toggle();
    setDefaultConstants();
    // chassis.drive_distance(-0.5);

    // 1st Ring
    chassis.turn_to_angle(-180);
    intake.forward();
    chassis.drive_distance(6);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // 2nd Ring
    chassis.turn_to_angle(-262);
    intake.forward();
    chassis.drive_distance(5);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);
    wait(250, msec);

    // 3rd Ring
    chassis.drive_distance(-4);
    chassis.turn_to_angle(-230);
    chassis.drive_distance(4);
    intake.forward();
    chassis.right_swing_to_angle(-262);
    chassis.drive_distance(2);
    wait(500, msec);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ladder
    chassis.drive_distance(-3);
    chassis.turn_to_angle(0);
    Lift.spinToPosition(240, deg, false);
    chassis.drive_distance(10.2);
    Lift.stop(coast);
    intake.stop(coast);
};

// void blue_awp() {
//     Lift.spinToPosition(-20, deg, false);

//     chassis.drive_distance(3.25);
//     chassis.right_swing_to_angle(-90);
//     chassis.left_swing_to_angle(-93);
//     chassis.drive_distance(-1.4);

//     vex::thread delayedIntakeThread(delayedIntakeStartThreadF);
//     Lift.spinToPosition(70, deg, true);
//     Lift.spinToPosition(260, deg, true);
//     Lift.spinToPosition(70, deg, true);
//     Lift.spinToPosition(-20, deg, false);
//     intake.stop();

//     // Go to & Pick up Mogo
//     chassis.turn_to_angle(-48);
//     chassis.drive_settle_time = 250;
//     chassis.drive_distance(-10.25);
//     chassis.drive_settle_time = 200;
//     Clamp.toggle();
//     // vex::thread intakePulseReverse(intakePulseReverseThreadF);
//     chassis.drive_distance(-2.75);

//     // Get 1st Ring (standalone)
//     chassis.turn_to_angle(-179);
//     intake.forward();
//     chassis.drive_distance(7);
//     wait(100, msec);

//     // Align for 2nd ring (stack)
//     chassis.turn_to_angle(-260);
//     chassis.drive_distance(4.4);
//     wait(300, msec);
//     chassis.left_swing_to_angle(-260);
//     intake.stop();
//     chassis.drive_distance(-5);

//     // Get 3rd Ring (stack)
//     intake.forward();
//     chassis.turn_to_angle(-247);
//     chassis.drive_distance(5.5);
//     wait(300, msec);

//     // Come back and aim for ladder
//     chassis.drive_distance(-3.25);
//     return;
//     chassis.turn_to_angle(15);
//     // Go to ladder
//     Lift.spinToPosition(200, deg, false);

//     intake.stop();
//     chassis.drive_distance(10);
//     chassis.drive_stop(hold);
// };
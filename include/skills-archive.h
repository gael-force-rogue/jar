
/*
void skills() {
    chassis.drive_stop(hold);

    vex::thread delayedIntakeStopThread;
    vex::thread intakePulseReverseThread;

    intake.forward();
    wait(700, msec);
    intake.stop();
    Lift.returnToDefaultPosition(false);

    // Mogo
    chassis.drive_distance(4.75);
    chassis.turn_to_angle(-90);
    chassis.drive_distance(-6);
    Clamp.toggle();

    // Ring 1
    chassis.drive_distance(-3);
    chassis.turn_to_angle(0);
    intake.forward();
    chassis.drive_distance(6);
    wait(200, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 2
    wait(700, msec);
    chassis.left_swing_to_angle(60);
    intake.forward();
    chassis.drive_max_voltage = 9;
    chassis.drive_distance(12);
    chassis.drive_max_voltage = 11;
    wait(200, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 3
    wait(300, msec);
    chassis.right_swing_to_angle(160);
    chassis.drive_max_voltage = 8;
    intake.forward();
    chassis.drive_distance(7);
    wait(400, msec);
    intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 4
    chassis.right_swing_to_angle(160);
    intake.forward();
    chassis.drive_distance(6.3);
    wait(600, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 5 & 6
    chassis.drive_max_voltage = 7;
    chassis.drive_distance(-6.5);
    chassis.turn_to_angle(185);
    intake.forward();
    chassis.drive_distance(7);
    wait(200, msec);
    chassis.drive_distance(5);
    // intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);
    wait(600, msec);
    chassis.drive_distance(-3);
    wait(150, msec);
    chassis.turn_to_angle(-45);
    chassis.drive_distance(-4.8);
    Clamp.toggle();
    intake.stop();

    return;

    // Long Distance Travel
    chassis.heading_kd = 0.9;
    chassis.turn_settle_time = 400;
    chassis.turn_settle_error = 0.25;
    chassis.turn_kd = 1;
    intake.forward();
    chassis.drive_distance(5.3);
    chassis.drive_stop(hold);
    chassis.turn_to_point(8, 1);
    intake.stop();
    chassis.drive_to_pose(8, 1, -91);
    chassis.drive_stop(hold);
    chassis.turn_to_point(4, 1);
    chassis.drive_to_pose(4, 1, -91);
    chassis.drive_stop(hold);

    chassis.turn_timeout = 1500;
    chassis.turn_to_angle(90);
    chassis.drive_distance(-7.5);
    chassis.drive_distance(0.5);
    Clamp.toggle();

    setDefaultConstants();
    chassis.turn_settle_error = 0.25;

    // Ring 1
    // chassis.drive_distance(-1);
    chassis.turn_to_angle(0);
    intake.forward();
    chassis.drive_distance(6);
    wait(200, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 2
    wait(700, msec);
    chassis.right_swing_to_angle(-58);
    intake.forward();
    chassis.drive_max_voltage = 9;
    chassis.drive_distance(12);
    chassis.drive_max_voltage = 11;
    wait(200, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 3
    wait(300, msec);
    chassis.left_swing_to_angle(-160);
    chassis.drive_max_voltage = 8;
    intake.forward();
    chassis.drive_distance(7);
    wait(400, msec);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 4
    chassis.left_swing_to_angle(-160);
    intake.forward();
    chassis.drive_distance(6.3);
    wait(600, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 5 & 6
    chassis.drive_max_voltage = 7;
    chassis.drive_distance(-6.5);
    chassis.turn_to_angle(-190);
    intake.forward();
    chassis.drive_distance(7);
    wait(100, msec);
    chassis.drive_distance(5);
    intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);
    wait(600, msec);
    chassis.drive_distance(-2);
    wait(150, msec);
    chassis.turn_to_angle(47);
    chassis.drive_distance(-4.8);
    Clamp.toggle();
    intake.stop();
    chassis.drive_distance(5.3);
};
*/

/*
void skills() {
    chassis.drive_stop(hold);

    vex::thread intakePulseReverseThread;
    vex::thread delayedIntakeStopThread;
    vex::thread intakeBurst;

    // Alliance Stake
    intake.forward();
    wait(800, msec);
    intake.stop();
    Lift.returnToDefaultPosition(true);

    // Mogo
    chassis.drive_distance(4.5);
    chassis.turn_to_angle(-90);
    chassis.drive_distance(-6.5);
    Clamp.toggle();

    // Ring 1
    chassis.drive_distance(-3);
    chassis.turn_to_angle(0);
    intake.spin(forward);
    chassis.drive_distance(6);
    wait(500, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Ring 2
    wait(500, msec);
    chassis.left_swing_to_angle(58);
    intake.spin(forward);
    // chassis.drive_max_voltage = 9;
    chassis.drive_distance(12);
    // chassis.drive_max_voltage = 11;
    wait(900, msec);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);

    // Rings 3,4,5
    intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);
    chassis.drive_distance(-3.6);
    // intake.spin(forward);
    // intake.stop();
    wait(200, msec);
    chassis.turn_to_angle(180);
    // intake.forward();
    chassis.drive_max_voltage = 4;
    // intake.spin(forward);
    chassis.drive_distance(17);

    // intake.forward();
    wait(700, msec);
    // intakePulseReverseThread = vex::thread(intakePulseReverseThreadF);
    chassis.drive_max_voltage = 10;

    // Ring 6
    chassis.turn_to_angle(55);
    // intake.forward();
    chassis.drive_distance(4);
    wait(600, msec);
    // intake.forward();

    // Drop Mogo
    // chassis.drive_distance(2);
    chassis.turn_to_angle(-27);
    // chassis.turn_to_angle(35);
    intake.spin(forward);
    wait(200, msec);
    delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);
    // intake.spin(reverse);
    // wait(200, msec);
    // delayedIntakeStopThread = vex::thread(delayedIntakeStopThreadF);
    chassis.drive_distance(-2);
    Clamp.toggle();

    chassis.drive_max_voltage = 11;

    // Ring 7
    chassis.drive_distance(1);
    chassis.turn_to_angle(2);
    // chassis.drive_distance(6);
    // chassis.turn_to_angle(-2);
    // intake.spin(forward);
    // wait(100, msec);
    chassis.drive_distance(28);
    // wait(600, msec);
    intakeBurst = vex::thread(intakeBurstF);
    // intake.spin(forward);
    // wait(50, msec);
    // intake.stop();
    // chassis.drive_distance(7);

    // Mogo
    chassis.turn_to_angle(156);
    wait(300, msec);
    chassis.drive_distance(-13);
    Clamp.toggle();
    // chassis.turn_to_angle(-90);
    // chassis.drive_distance(-18);
    // Clamp.toggle();

    // Score Mogo
    Knocker.toggle();
    wait(200, msec);
    chassis.turn_to_angle(67);
    chassis.drive_distance(10);
    chassis.drive_stop(brake);
    chassis.turn_to_angle(220);
    // chassis.turn_to_angle(-270);
}
*/
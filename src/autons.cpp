#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants() {
    // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
    chassis.set_drive_constants(10, 2, 0, 10, 0);
    chassis.set_heading_constants(6, 1.2, 0, 1, 0);
    chassis.set_turn_constants(7, .2, 0, 1.3, 0);
    chassis.set_swing_constants(12, .3, .001, 2, 15);

    // Each exit condition set is in the form of (settle_error, settle_time, timeout).
    chassis.set_drive_exit_conditions(1.5, 300, 5000);
    chassis.set_turn_exit_conditions(0.5, 100, 1000);
    chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */
void odom_constants() {
    default_constants(); 
    chassis.heading_max_voltage = 10;
    chassis.drive_max_voltage = 8;
    chassis.drive_settle_error = 3;
    chassis.boomerang_lead = .5;
    chassis.drive_min_voltage = 0;
}

void mogo_drop_threadF() {
  wait(750, msec);
  Clamp.toggle();
};

void intake_stop_threadF() {
  wait(1500, msec);
  Intake.stop();
}

void red_auton_period_old() {
    //  1 tile =8.4,8.2

    // Mogo
    chassis.drive_distance(-9.4);
    // wait(100, msec);
    Clamp.toggle();

    // 2nd Ring
    Intake.spin(fwd, 100, percent);
    wait(100, msec);
    chassis.turn_settle_time = 200;
    chassis.turn_to_angle(85);
    chassis.drive_distance(5);
    chassis.turn_settle_time = 100;

    // 3rd Ring
    chassis.turn_to_angle(150);
    chassis.drive_distance(5);
    wait(150, msec);
    
    // Align & Perform long distance drive
    Intake.stop();
    chassis.drive_distance(-9.75);
    Intake.spin(fwd, 100, percent);
    wait(100, msec);
    chassis.turn_to_angle(240);

    vex::thread mogoDropThread(mogo_drop_threadF);
    chassis.drive_max_voltage = 12;
    chassis.drive_distance(26);
    chassis.drive_max_voltage = 10;

    // chassis.turn_to_angle(150);
    // chassis.drive_distance(-3);
    // Clamp.toggle();
    // chassis.drive_distance(3);
    chassis.turn_to_angle(290);
    chassis.drive_distance(-6);
    Clamp.toggle();
    chassis.turn_to_angle(240);
    Intake.spin(fwd, 100, pct);
    chassis.drive_distance(5);
    chassis.turn_timeout = 1000;
    chassis.turn_to_angle(120);
    chassis.drive_distance(8);
    Intake.stop();
}

void red_auton_period() {
  //  1 tile =8.4,8.2

    // Mogo
    chassis.drive_distance(-9.4);
    // wait(100, msec);
    Clamp.toggle();

    // 2nd Ring
    Intake.spin(fwd, 100, percent);
    chassis.turn_to_angle(80);
    chassis.drive_distance(5);

    // 3rd Ring
    chassis.turn_to_angle(150);
    chassis.drive_distance(5);
    wait(150, msec);
    
    // Align & Perform long distance drive
    vex::thread intakeStopThread(intake_stop_threadF);
    chassis.drive_distance(-9.75);
    chassis.drive_stop(brake);
    // Intake.spin(fwd, 100, percent);
    // wait(1000, msec);
    // Intake.stop();
    // chassis.turn_to_angle(240);

    // vex::thread mogoDropThread(mogo_drop_threadF);
    // chassis.drive_max_voltage = 12;
    // chassis.drive_distance(26);
    // chassis.drive_max_voltage = 10;

    // // chassis.turn_to_angle(150);
    // // chassis.drive_distance(-3);
    // // Clamp.toggle();
    // // chassis.drive_distance(3);
    // chassis.turn_to_angle(290);
    // chassis.drive_distance(-6);
    // Clamp.toggle();
    // chassis.turn_to_angle(240);
    // Intake.spin(fwd, 100, pct);
    // chassis.drive_distance(5);
    // chassis.turn_timeout = 1000;
    // chassis.turn_to_angle(120);
    // chassis.drive_max_voltage = 12;
    // chassis.drive_distance(10);
    // Intake.stop();
}

void blue_auton_period() {
    //  1 tile =8.4,8.2

    // Mogo
    chassis.drive_distance(-9.4);
    // wait(100, msec);
    Clamp.toggle();

    // 2nd Ring
    Intake.spin(fwd, 100, percent);
    chassis.turn_to_angle(-80);
    chassis.drive_distance(5);

    // 3rd Ring
    chassis.turn_to_angle(-150);
    chassis.drive_distance(5);
    wait(150, msec);
    
    // Align & Perform long distance drive
    vex::thread intakeStopThread(intake_stop_threadF);
    chassis.drive_distance(-9.75);
    Intake.spin(fwd, 100, percent);
    wait(100, msec);
    chassis.turn_to_angle(-240);

    vex::thread mogoDropThread(mogo_drop_threadF);
    chassis.drive_max_voltage = 12;
    chassis.drive_distance(26);
    chassis.drive_max_voltage = 10;

    // chassis.turn_to_angle(150);
    // chassis.drive_distance(-3);
    // Clamp.toggle();
    // chassis.drive_distance(3);
    chassis.turn_to_angle(-290);
    chassis.drive_distance(-6);
    Clamp.toggle();
    chassis.turn_to_angle(-240);
    Intake.spin(fwd, 100, pct);
    chassis.drive_distance(5);
    chassis.turn_timeout = 1000;
    chassis.turn_to_angle(-120);
    chassis.drive_max_voltage = 12;
    chassis.drive_distance(10);
    Intake.stop();
}

void npc_auton() {
  chassis.drive_distance(4);
}

void red_elims_auton() {
  // Mogo
    chassis.drive_distance(-9.4);
    // wait(100, msec);
    Clamp.toggle();

    // 2nd Ring
    wait(500, msec);
    Intake.spin(fwd, 100, percent);
    wait(750, msec);
    chassis.turn_to_angle(75);
    chassis.drive_distance(5);

    // 3rd Ring
    chassis.turn_to_angle(150);
    chassis.drive_distance(4);
    wait(2000, msec);
    
    // Align & Perform long distance drive
    Intake.stop();
    chassis.drive_distance(-4);
    chassis.drive_stop(brake);

    // 4th ring
    // chassis.turn_to_angle(115);
    // Intake.spin(fwd, 100, percent);
    // wait(1000, msec);
    // chassis.drive_distance(4);
    // wait(1000, msec);
    // chassis.drive_distance(-4);
    // wait(500, msec);
    // Intake.stop();
}
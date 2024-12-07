#include <iostream>

#include "vex.h"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

    // Pick your drive setup from the list below:
    // ZERO_TRACKER_NO_ODOM
    // ZERO_TRACKER_ODOM
    // TANK_ONE_FORWARD_ENCODER
    // TANK_ONE_FORWARD_ROTATION
    // TANK_ONE_SIDEWAYS_ENCODER
    // TANK_ONE_SIDEWAYS_ROTATION
    // TANK_TWO_ENCODER
    // TANK_TWO_ROTATION
    // HOLONOMIC_TWO_ENCODER
    // HOLONOMIC_TWO_ROTATION
    //
    // Write it here:
    ZERO_TRACKER_ODOM,

    // Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
    // You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

    // Left Motors:
    motor_group(Left1, Left2, Left3),

    // Right Motors:
    motor_group(Right1, Right2, Right3),

    // Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
    PORT12,

    // Input your wheel diameter. (4" omnis are actually closer to 4.125"):
    3.25,

    // External ratio, must be in decimal, in the format of input teeth/output teeth.
    // If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
    // If the motor drives the wheel directly, this value is 1:
    0.75,

    // Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
    // For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
    360,

    /*---------------------------------------------------------------------------*/
    /*                                  PAUSE!                                   */
    /*                                                                           */
    /*  The rest of the drive constructor is for robots using POSITION TRACKING. */
    /*  If you are not using position tracking, leave the rest of the values as  */
    /*  they are.                                                                */
    /*---------------------------------------------------------------------------*/

    // If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

    // FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
    // LF:      //RF:
    PORT1, -PORT2,

    // LB:      //RB:
    PORT3, -PORT4,

    // If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
    // If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
    // If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
    11,

    // Input the Forward Tracker diameter (reverse it to make the direction switch):
    3.25,

    // Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
    // For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
    // This distance is in inches:
    6,

    // Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
    0,

    // Sideways tracker diameter (reverse to make the direction switch):
    0,

    // Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
    0);

bool auton_started = false;

void autonomous(void) {
    auton_started = true;
    logAuton();
    runAuton(AUTON);
}

void hangThreadF() {
    while (1) {
        if (Controller.ButtonDown.pressing()) {
            while (Controller.ButtonDown.pressing()) {
                wait(10, msec);
            }
            Hang.toggle();
            Knocker.close();
        };
        if (Controller.ButtonUp.pressing()) {
            while (Controller.ButtonUp.pressing()) {
                wait(10, msec);
            };
            Lift.cycle();
        };
        wait(20, msec);
    };
}

void usercontrol(void) {
    Lift.setStopping(hold);
    Lift.setVelocity(100, percent);
    // Lift.returnToDefaultPosition(false);

    vex::thread intakeSearchingThread(intakeSearchingThreadF);
    vex::thread hangThread(hangThreadF);

    bool manualIntakeInterrupt = false;
    while (1) {
        chassis.control_arcade();

        // Lift Manual Interrupt
        if (Controller.ButtonL1.pressing()) {
            Lift.state = LiftState::STANDBY;
            Lift.controlled = false;
            Lift.forward();
        } else if (Controller.ButtonL2.pressing()) {
            Lift.state = LiftState::STANDBY;
            Lift.controlled = false;
            Lift.backward();
        } else if (Lift.state == LiftState::STANDBY && !Lift.controlled) {
            Lift.stop();
        };

        // Clamp
        if (Controller.ButtonB.pressing()) {
            while (Controller.ButtonB.pressing()) {
                wait(10, msec);
            }
            Clamp.close();
        } else if (Controller.ButtonA.pressing()) {
            while (Controller.ButtonA.pressing()) {
                wait(10, msec);
            }
            Clamp.open();
        }

        // Knocker
        if (Controller.ButtonY.pressing()) {
            while (Controller.ButtonY.pressing()) {
                wait(10, msec);
            }
            Knocker.toggle();
        }

        // Hang
        // threaded

        // Intake
        if (Controller.ButtonR2.pressing()) {
            manualIntakeInterrupt = true;
            intake.forward();
        } else if (Controller.ButtonR1.pressing()) {
            manualIntakeInterrupt = true;
            intake.backward();
        } else if (intake.state == IOFF || manualIntakeInterrupt) {
            manualIntakeInterrupt = false;
            intake.stop();
        }

        wait(20, msec);
    }
}

int main() {
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);
    logAuton();

    if (Brain.Battery.capacity() < 15) {
        Controller.rumble("-.-.-");
    };

    // while (!auton_started) {
    //     Brain.Screen.clearScreen();
    //     Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    //     Brain.Screen.printAt(5, 40, "Battery Percentage:      %d", Brain.Battery.capacity());
    //     Brain.Screen.printAt(5, 60, "Chassis Heading Reading: %f", chassis.get_absolute_heading());
    //     // Brain.Screen.printAt(5, 120, "Selected Auton: %s", STRINGIFY_AUTON(AUTON));
    //     task::sleep(10);
    // }

    while (true) {
        wait(100, msec);
    }
}

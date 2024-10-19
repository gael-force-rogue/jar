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
    ZERO_TRACKER_NO_ODOM,

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
    3,

    // Input the Forward Tracker diameter (reverse it to make the direction switch):
    3.25,

    // Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
    // For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
    // This distance is in inches:
    5.75,

    // Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
    0,

    // Sideways tracker diameter (reverse to make the direction switch):
    0,

    // Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
    0);

int current_auton_selection = 2;
bool auto_started = false;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();
    default_constants();
    

    while (!auto_started) {
        Brain.Screen.clearScreen();
        Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
        Brain.Screen.printAt(5, 40, "Battery Percentage:");
        Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
        Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
        Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
        Brain.Screen.printAt(5, 120, "Selected Auton:");
        Brain.Screen.printAt(5, 140, "Auton %f", current_auton_selection + 1);
        if (Brain.Screen.pressing()) {
            while (Brain.Screen.pressing()) {};
            current_auton_selection++;
        } else if (current_auton_selection == 8) {
            current_auton_selection = 0;
        }
        task::sleep(10);
    }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
    auto_started = true;
    switch (current_auton_selection) {
        case 0:
            red_auton_period();
            break;
        case 1:
            red_auton_period();
            break;
        case 2:
            blue_auton_period();
            break;
        case 3:
            swing_test();
            break;
        case 4:
            full_test();
            break;
        case 5:
            odom_test();
            break;
        case 6:
            tank_odom_test();
            break;
        case 7:
            holonomic_odom_test();
            break;
    }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
    controller Controller(controllerType::primary);

    // User control code here, inside the loop
    while (1) {
        // This is the main execution loop for the user control program.
        // Each time through the loop your program should update motor + servo
        // values based on feedback from the joysticks.

        // ........................................................................
        // Insert user code here. This is where you use the joystick values to
        // update your motors, etc.
        // ........................................................................

        // Replace this line with chassis.control_tank(); for tank drive
        // or chassis.control_holonomic(); for holo drive.
        chassis.control_arcade();

        if (Controller.ButtonB.pressing()) {
            while (Controller.ButtonB.pressing()) {
                wait(10, msec);
            }
            Clamp.close();
        }
        if (Controller.ButtonA.pressing()) {
            while (Controller.ButtonA.pressing()) {
                wait(10, msec);
            }
            Clamp.open();
        }
        if (Controller.ButtonY.pressing()) {
            while (Controller.ButtonY.pressing()) {
                wait(10, msec);
            }
            Knocker.toggle();
        }
        if (Controller.ButtonUp.pressing()) {
            while (Controller.ButtonUp.pressing()) {
                wait(10, msec);
            }
            Hang.toggle();
        }

        if (Controller.ButtonR2.pressing()) {
            Intake.spin(forward, 100, percent);
        } else if (Controller.ButtonR1.pressing()) {
            Intake.spin(reverse, 100, percent);
        } else {
            Intake.stop();
        }

        if (Controller.ButtonL2.pressing()) {
            Lift.spin(forward, 100, percent);
        } else if (Controller.ButtonL1.pressing()) {
            Lift.spin(reverse, 100, percent);
        } else {
            Lift.stop();
        }

        wait(20, msec);  // Sleep the task for a short amount of time to
                         // prevent wasted resources.
    }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    // Set up callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);

    // Run the pre-autonomous function.
    pre_auton();

    // Prevent main from exiting with an infinite loop.
    while (true) {
        wait(100, msec);
    }
}

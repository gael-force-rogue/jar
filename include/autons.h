#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void red_auton_period();
void blue_auton_period();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();
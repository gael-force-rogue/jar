#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

#define STRINGIFY_AUTON2(content) #content
#define STRINGIFY_AUTON(content) STRINGIFY_AUTON2(content)

#define DELAY(expr, t) \
    wait(t, msec);     \
    expr;

void intakePulseReverseThreadF();
void delayedIntakeThreadF();

void red_awp();
void blue_awp();
void red_elims();
void blue_elims();
void skills();
void npc();

void intakeColorSortThreadF();

void runAuton(Auton auton);
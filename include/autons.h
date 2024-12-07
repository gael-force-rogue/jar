#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

#define DELAY(expr, t) \
    wait(t, msec);     \
    expr;

void intakePulseReverseThreadF();
void delayedIntakeStartThreadF();
void delayedIntakeStopThreadF();
void shortDelayedIntakeStopThreadF();
void intakeBurstF();
void disconnectThreadF();

void red_awp();
void blue_awp();
void red_mogorush();
void blue_mogorush();
void red_elims();
void blue_elims();
void skills();
void npc();

void setDefaultConstants();
void setOdometryConstants();

void runAuton(Auton auton);
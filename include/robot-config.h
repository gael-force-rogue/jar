#include <iostream>

using namespace vex;

enum Auton {
    RED = 1,
    BLUE = 2,
    AWP = 4,
    MOGORUSH = 8,
    ELIMS = 16,
    SKILLS = 32,
    NPC = 64,
    RED_AWP = RED | AWP,
    BLUE_AWP = BLUE | AWP,
    RED_ELIMS = RED | ELIMS,
    BLUE_ELIMS = BLUE | ELIMS,
    RED_MOGORUSH = RED | MOGORUSH,
    BLUE_MOGORUSH = BLUE | MOGORUSH,
};

#define AUTON BLUE_MOGORUSH

enum IntakeState {
    SEARCHING,
    SCORING,
    OFF
};

class Intake : public motor {
   public:
    vex::optical colorSensor;
    IntakeState state = OFF;

    Intake(int port, bool reverse, int opticalPort) : vex::motor(port, reverse), colorSensor(opticalPort) {};

    inline void forward(float velocity = 100) {
        this->spin(fwd, velocity, pct);
    };

    inline void backward(float velocity = 100) {
        this->spin(fwd, -velocity, pct);
    };

    inline void spinBy(float pos) {
        this->spinToPosition(this->position(deg) + pos, deg, true);
    };

    void search();

    bool launchRingIfNeeded();
};

float normalize360(float angle);

class LiftMotor : public motor {
   public:
    float defaultPosition = 0;

    LiftMotor(int index, bool reverse) : vex::motor(index, reverse) {};

    inline void forward() {
        this->spin(fwd, 100, pct);
    };

    inline void backward() {
        this->spin(fwd, -100, pct);
    };

    inline float relativePosition() {
        return normalize360(position(deg));
    };

    inline void spinToRelativePosition(float angle, bool waitForCompletion) {
        this->spinToPosition(position(deg) - relativePosition() + angle, deg, waitForCompletion);
    };

    inline void returnToDefaultPosition(bool waitForCompletion) {
        this->spinToRelativePosition(defaultPosition, true);
    };

    void score();
};

class Piston : public pneumatics {
   private:
    bool isOpen;

   public:
    /**
     * @brief Creates a new Piston
     * @param piston vex::pneumatics to wrap
     * @param startsOpen Whether the piston starts open or closed
     */
    Piston(pneumatics piston, bool startsOpen) : vex::pneumatics(piston), isOpen(startsOpen) {};

    void toggle() {
        if (isOpen) {
            this->close();
        } else {
            this->open();
        }
        isOpen = !isOpen;
    }
};

extern brain Brain;
extern controller Controller;

extern motor Left1;
extern motor Left2;
extern motor Left3;
extern motor Right1;
extern motor Right2;
extern motor Right3;

extern Intake intake;
extern LiftMotor Lift;

extern Piston Clamp;
extern Piston Hang;
extern Piston Knocker;

void intakeSearchingThreadF();
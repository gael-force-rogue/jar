using namespace vex;

class IntakeMotor : public motor {
   public:
    IntakeMotor(int index, bool reverse) : vex::motor(index, reverse) {};

    inline void forward() {
        this->spin(fwd, 100, pct);
    }

    inline void backward() {
        this->spin(fwd, -100, pct);
    }
};

class LiftMotor : public motor {
   public:
    float defaultPosition = -10;

    LiftMotor(int index, bool reverse) : vex::motor(index, reverse) {};

    void score();

    inline void forward() {
        this->spin(fwd, 100, pct);
    };

    inline void backward() {
        this->spin(fwd, -100, pct);
    };

    inline void returnToDefaultPosition(bool waitForCompletion) {
        this->spinToPosition(defaultPosition, deg, waitForCompletion);
    };
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

class ColorSensor : public optical {
   public:
    ColorSensor(int port) : vex::optical(port) {};

    inline bool ringDetected() {
        auto rgb = this->getRgb();
        return rgb.red > 200 || rgb.blue > 200;
    };
};

extern brain Brain;
extern controller Controller;

extern motor Left1;
extern motor Left2;
extern motor Left3;
extern motor Right1;
extern motor Right2;
extern motor Right3;

extern IntakeMotor Intake;
extern LiftMotor Lift;

extern Piston Clamp;
extern Piston Hang;
extern Piston Knocker;

extern ColorSensor colorSensor;

enum Auton {
    RED_AWP,
    BLUE_AWP,
    RED_ELIMS,
    BLUE_ELIMS,
    SKILLS,
    NPC
};

#define AUTON SKILLS
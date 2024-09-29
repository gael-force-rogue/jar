using namespace vex;

extern brain Brain;

// To set up a motor called LeftFront here, you'd use
// extern motor LeftFront;

// Add your devices below, and don't forget to do the same in robot-config.cpp:
extern motor Left1;
extern motor Left2;
extern motor Left3;
extern motor Right1;
extern motor Right2;
extern motor Right3;

extern motor Intake;
extern motor Lift;

class Piston {
   public:
    vex::pneumatics vPiston;  // Member that needs initialization
    bool isOpen;

    // Constructor with initializer list
    Piston(vex::pneumatics vp, bool deployOnStart)
        : vPiston(vp), isOpen(!deployOnStart) {
        toggle();
    }

    // Additional methods if any
    void toggle() {
        if (isOpen) {
            vPiston.close();
        } else {
            vPiston.open();
        }
        isOpen = !isOpen;
    }

    void open() {
        vPiston.open();
        isOpen = true;
    }

    void close() {
        vPiston.close();
        isOpen = false;
    }
};

extern Piston Clamp;
extern Piston Hang;
extern Piston Knocker;

void vexcodeInit(void);
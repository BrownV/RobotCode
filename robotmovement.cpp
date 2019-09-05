#include "robot-config.h"
          

int main() {
    BackLeft.setVelocity(250,vex::velocityUnits::rpm);
    BackRight.setVelocity(250,vex::velocityUnits::rpm);
    FrontLeft.setVelocity(250,vex::velocityUnits::rpm);
    FrontRight.setVelocity(250,vex::velocityUnits::rpm);
    FlapLeft.setVelocity(250,vex::velocityUnits::rpm);
    FlapRight.setVelocity(250,vex::velocityUnits::rpm);
    while(true) {
      //Drivetrain
        BackLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        FrontLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        BackRight.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
        FrontRight.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
      //Flapper
        FlapLeft.spin(vex::directionType::fwd), Controller1.ButtonR1.pressing()., vex::velocityUnits::pct); //PCT- Percentage-button press?
        FlapRight.spin(vex::directionType::rev), Controller1.ButtonL1.pressing(), vex::velocityUnits::pct);
    `   FlapLeft.spin(vex::directionType::fwd), Controller1.ButtonR2.pressing(), vex::velocityUnits::pct); //PCT- Percentage-button press?
        FlapRight.spin(vex::directionType::rev), Controller1.ButtonL1.pressing(), vex::velocityUnits::pct);

        vex::task::sleep(20);
        
      
    }
}

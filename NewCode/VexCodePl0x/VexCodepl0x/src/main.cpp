/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\20brovin                                         */
/*    Created:      Tue Sep 17 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
vex::motor BackLeft = vex::motor(vex::PORT11);
vex::motor BackRight = vex::motor(vex::PORT20);
vex::motor FrontLeft = vex::motor(vex::PORT1);
vex::motor FrontRight = vex::motor(vex::PORT10);
vex::motor FlapLeft = vex::motor(vex::PORT9);
vex::motor FlapRight = vex::motor(vex::PORT2);
vex::motor Dock = vex::motor(vex::PORT7);
vex::controller Controller1;



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

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

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    //Drivetrain
    BackLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    FrontLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    BackRight.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    FrontRight.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    //Flapper
    FlapLeft.spin(vex::directionType::fwd, Controller1.ButtonR1.pressing(), vex::velocityUnits::pct); //PCT- Percentage-button press?
    FlapRight.spin(vex::directionType::rev, Controller1.ButtonL1.pressing(), vex::velocityUnits::pct);
    FlapLeft.spin(vex::directionType::fwd, Controller1.ButtonR2.pressing(), vex::velocityUnits::pct); //PCT- Percentage-button press?
    FlapRight.spin(vex::directionType::rev, Controller1.ButtonL1.pressing(), vex::velocityUnits::pct);
    //Dock
    Dock.spin(vex::directionType::fwd, Controller1.ButtonX.pressing(), vex::velocityUnits::pct);
    Dock.spin(vex::directionType::rev, Controller1.ButtonB.pressing(), vex::velocityUnits::pct);
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    BackLeft.setVelocity(250,vex::velocityUnits::rpm);
    BackRight.setVelocity(250,vex::velocityUnits::rpm);
    FrontLeft.setVelocity(250,vex::velocityUnits::rpm);
    FrontRight.setVelocity(250,vex::velocityUnits::rpm);
    FlapLeft.setVelocity(250,vex::velocityUnits::rpm);
    FlapRight.setVelocity(250,vex::velocityUnits::rpm);
    Dock.setVelocity(125,vex::velocityUnits::rpm);
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}
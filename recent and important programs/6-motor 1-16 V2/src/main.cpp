/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    16, 18, 8, 20   
// catapult             motor         19    
// Intake               motor_group   2, 3        
// piston               digital_out   A               
// piston_2             digital_out   B         
// inertial_1           inertial      14      
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex; 

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int auton = 0;
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  catapult.setVelocity(100, percent);
  Drivetrain.setDriveVelocity(100, percent);
  Intake.setVelocity(100, percent);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(1,1,240,120);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(240,120,240,120);
  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(240,1,240,120);
  Brain.Screen.setFillColor(purple);
  Brain.Screen.drawRectangle(1,120,240,120);
  // lines 44-52 of the = code draws 4 different colored rectangles
  Brain.Screen.setCursor(4,7);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.print("close");
  Brain.Screen.setCursor(10,7);
  Brain.Screen.setFillColor(purple);
  Brain.Screen.print("Skills 2");
  Brain.Screen.setCursor(10,33);
  Brain.Screen.setFillColor(red);
  Brain.Screen.print("far");
  Brain.Screen.setCursor(4,33);
  Brain.Screen.setFillColor(black);
  Brain.Screen.print("win point test 3");

  //lines 54-65 print the autons names on the correct square
  
  while (true){
    Brain.Screen.setFont(monoXXL);
    if (Brain.Screen.pressing()){
     if (Brain.Screen.xPosition()< 240){
       if (Brain.Screen.yPosition()<120){
        auton = 1;
         Brain.Screen.setCursor(2,8);
         Brain.Screen.print(auton);
         wait (20,msec);
       }
     } 
     if (Brain.Screen.xPosition()> 240){
       if (Brain.Screen.yPosition()>120){
         auton = 4;
         Brain.Screen.setCursor(2,8);
         Brain.Screen.print(auton);
         wait (20,msec);
       }
     } 
     if (Brain.Screen.xPosition()< 240){
       if (Brain.Screen.yPosition()>120){
         auton = 2;
         Brain.Screen.setCursor(2,8);
         Brain.Screen.print(auton);
         wait (20,msec);
       }
     }
     if (Brain.Screen.xPosition()> 240){
       if (Brain.Screen.yPosition()<120){
         auton = 3;
         Brain.Screen.setCursor(2,8);
         Brain.Screen.print(auton);
         wait (20,msec);
       }
     wait (20,msec);}  
    wait (20,msec);}
    wait(20, msec);
  }

  //lines 71-103 detect which part of the screen you touch and set it to a variable 

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

void autonomous(void) {
  inertial_1.calibrate();
 //match//
 if (auton == 1) {
  inertial_1.calibrate();
  inertial_1.calibrate();
  wait (1,sec);
  piston_2.set(false);
  piston.set(false);
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.turnFor(left, 4, degrees);
  Drivetrain.driveFor(reverse, 10, inches);
  piston.set(true);
  Drivetrain.driveFor(forward, 6.5, inches);
  Drivetrain.turnFor(left, 52, degrees);
  piston.set(false);
  Drivetrain.driveFor(forward, 42, inches);
  Drivetrain.turnFor(left, 5, degrees);
   /*Drivetrain.driveFor(reverse, 4, inches);
   Drivetrain.turnFor(right, 35, degrees);
   Drivetrain.driveFor(reverse, 20, inches);
   Drivetrain.turnFor(right, 75, degrees);
   Drivetrain.driveFor(reverse, 10, inches);
   Drivetrain.driveFor(forward, 7, inches);
   wait (20,msec);
   Drivetrain.turnFor(left,45,degrees);
   Drivetrain.driveFor(forward, 26, inches);
   Drivetrain.turnFor(left,52,degrees);
   Drivetrain.driveFor(forward, 34, inches);
   Intake.spinFor(-140,degrees);*/
   

  //auton with no wings//
/*Drivetrain.turnFor(left,6,degrees);
Drivetrain.driveFor(reverse,34,inches);
Drivetrain.turnFor(7,degrees);
Drivetrain.driveFor(forward, 19, inches);
Drivetrain.turnFor(right,105,degrees);
Drivetrain.driveFor(forward, 3.5, inches);
Drivetrain.turnFor(right,75,degrees);
Drivetrain.driveFor(forward,24,inches);
Drivetrain.turnFor(left,5,degrees);
Drivetrain.driveFor(forward,7,inches,false);
Intake.spinFor(90,degrees);
Drivetrain.turnFor(left,90,degrees);
Drivetrain.driveFor(forward,10,inches);*/
  wait (20, msec);
  }
  
  //skills//
  if (auton == 2) {
   Drivetrain.setDriveVelocity(100,percent);
   Drivetrain.driveFor(forward,3,inches);
   wait (0.5, sec);
   Drivetrain.turnFor(right,28,degrees);
   catapult.spinFor(reverse, 106, turns );
   Drivetrain.turnFor(right,33,degrees);
   Drivetrain.driveFor(reverse,50,inches);
   Drivetrain.turnFor(left,5,degrees);
   Drivetrain.driveFor(reverse,45,inches);
   Drivetrain.turnFor(left,115,degrees);
   Drivetrain.driveFor(reverse,24,inches);
   Drivetrain.turnFor(left,80,degrees);
   Drivetrain.driveFor(reverse,28,inches);
   Drivetrain.turnFor(right,135,degrees);
   piston_2.set(true);
   piston.set(true);
   Drivetrain.driveFor(reverse,33,inches);
   Drivetrain.driveFor(forward,30,inches);   
   piston_2.set(false);
   piston.set(false);
   Drivetrain.turnFor(left,45,degrees);
   Drivetrain.driveFor(reverse,56,inches);
   Drivetrain.turnFor(left,135,degrees);
   piston_2.set(true);
   piston.set(true);
   Drivetrain.driveFor(reverse,36,inches);
   Drivetrain.driveFor(forward,30,inches);
   piston_2.set(false);
   piston.set(false);
   }
   //win point test//
   if (auton == 3) {
   /*Drivetrain.driveFor(forward,30,inches);
   Drivetrain.driveFor(reverse,30,inches);
   catapult.spinFor(reverse,4,turns);
   //grab tri-ball//
   Drivetrain.driveFor(forward,60,inches);
   Drivetrain.turnFor(45,degrees);
   //touches bar//*/
   Drivetrain.setDriveVelocity(100,percent);
   Drivetrain.driveFor(forward,34,inches);
   Drivetrain.setDriveVelocity(70,percent);
   Drivetrain.driveFor(reverse,30,inches);
   Drivetrain.turnFor(right,90,degrees);
   Drivetrain.driveFor(reverse,5,inches);
   wait (2, sec);
   Drivetrain.turnFor(right,45,degrees);
   Drivetrain.driveFor(forward,40,inches);
   wait (20, msec);
   }
   if (auton == 4) {
   Drivetrain.setDriveVelocity(100,percent);
   Drivetrain.turnFor(left,5,degrees);
  Drivetrain.driveFor(forward,37,inches);
  Drivetrain.driveFor(forward,2,inches,false);
  Intake.spinFor(120,degrees);
  wait (1,sec);
  Intake.spinFor(120,degrees,false);
  Drivetrain.driveFor(reverse, 7, inches);
  Drivetrain.driveFor(forward, 13, inches);
  Drivetrain.turnFor(left,7,degrees);
  Drivetrain.driveFor(reverse, 22, inches);
  Drivetrain.turnFor(left,70,degrees);
  Drivetrain.driveFor(forward,41,inches);
  Drivetrain.turnFor(right,60,degrees);
  Drivetrain.driveFor(forward,20,inches);
  Drivetrain.setDriveVelocity(40,percent);
  Drivetrain.driveFor(forward,9,inches,false);
  Intake.spinFor(-220,degrees);
  Drivetrain.turnFor(right,100,degrees);
  Drivetrain.driveFor(forward,20,inches);
  Intake.spinFor(190,degrees);
  wait (20, msec);
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
  // User control code here, inside the loop
  Drivetrain.setDriveVelocity(100,percent);
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
  while (true) {
    if (Controller1.ButtonX.pressing()) {
      piston.set(true);
    } else if (Controller1.ButtonY.pressing()) {
      piston.set(false);
    }
    else if (Controller1.ButtonA.pressing()){
      piston_2.set(true);
    }
    else if (Controller1.ButtonB.pressing()){
      piston_2.set(false);
      wait (20,msec);
    }
    wait(20, msec);
  }
 /*while (true) {
    if (Controller1.ButtonA.pressing()) {
      zone_standoff.set(true);
    } else if (Controller1.ButtonY.pressing()) {
      zone_standoff.set(false);*/
      wait (20, msec);
     // Sleep the task for a short amount of time to
     // prevent wasted resources.
    }
    {
      //controller1.ButtonL2.catapult.spin(reverse)
    wait (20,msec);
    }
  /*catapult.setVelocity(100,percent);
  while (true) {
  catapult.setVelocity(100,percent);
  if (Controller1.ButtonL1.pressing()) 
    catapult.spinFor(reverse, 90, degrees);*/
  /*}
  while (true) {
  if (Controller1.ButtonUp.pressing()) 
    catapult.spin(forward);
 }*/
 wait (20,msec);
}

void driverControl() {
  while (true) {
    if (Controller1.ButtonY.pressing()) {
      piston.set(true);
    } else if (Controller1.ButtonX.pressing()) {
      piston.set(false);
    }
    wait(20, msec);
  }
   while (true) 
   if (Controller1.ButtonB.pressing()) {
     piston_2.set(true);
   } else if (Controller1.ButtonA.pressing()) {
     piston_2.set(false);
   }
   wait(20, msec);
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

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include<cstdlib>
#include "Input_Validation_Extended.h"
using namespace std;

// Global Variables
const string red = "\033[31m";
const string resetColor = "\033[00m";
string choice;

// Prompts user to select menu option
void Menu()
{
  cout << "\nMENU" << endl; 
  cout << "1: Velocity Calculator" <<endl; 
  cout << "2: Acceleration Calculator" << endl; 
  cout << "3: Motion Calculator" << endl; 
  cout << "4: Force Calculator" <<endl; 
  cout << "5: Weight Calculator" << endl; 
  cout << "6: Momentum Calculator" << endl;
  cout << "E: Exit" << endl; 
  cout << "X: Clear The Screen" << endl;  

  cout << "\nPlease Enter an Menu Selection: "; 
}

// Calculates and displays velocity
void velocity(string unit1, string unit2, double ds, double dt)
{
 // Declares a variable to hold Velocity, and sets equation 
 double vel;
 vel = ds/dt;
 
  // Displays equation w/variable values
  cout << "\nThe velocity is calculated by dividing ds by dt.\n" <<
  "\nTherefore the velocity is equal to " << ds << " " << unit1  << "/" << dt << " " 
  << unit2 << " " <<endl ; 

  // Displays result with color
  cout << "The calculated velocity is " <<fixed <<setprecision(4) << red << vel << resetColor << " " << unit1 << "/" << unit2 << "." << endl;

}

// Calculates and displays accerlation
void accerlation(string unit1, string unit2, double dv, double dt)
{
  // Declares a variable to hold accerlation, and sets the equation 
  double acc;
  acc = dv/dt;
  
  // Displays equation w/variable values
  cout << "\nThe accerlation is calculated by dividing dv by dt.\n" <<
  "\nTherefore the accerlation is equal to " << dv << " " << unit1  << "/" 
  << dt << " "  << unit2 << " " <<endl ; 
  
  // Displays result with color
  cout << "The calculated accerlation is " <<fixed <<setprecision(4) << red << acc << resetColor << " " << unit1 << "/" << unit2 << "." << endl;
}

// Calculates and displays the 4 motion equations
void motion(double velNot,double vel,double acc,double time,double sNot,double sVar,string mChoice,string unit1,string unit2)
{
  // Declares a variable to hold motions val, and sets the equations 
  double Ma,Ms,Mv2,Mv;
  
  Ma  = velNot + (acc*time);
  Ms  = sNot + (velNot * time) + ((.5)*(acc * pow(time,2)));
  Mv2 = pow(velNot,2) + ((acc)*(2)*(sVar-sNot));
  Mv  = (.5)*(vel + velNot);

  // Calculates Ma
  if(mChoice == "1")
  {   
      // Displays Equation
      cout << "V = " << velNot << " + " << "(" << acc << " x " << time << ")\n"; 
      
      // Displays Result
      cout << "V = " << fixed << setprecision(4) << red << Ma << " " << unit1 << "/"<< unit2 << resetColor << endl;
  }
  // Calculates Ms
  else if( mChoice == "2")
  {   
    // Displays Equation
      cout << "\nS is equal to " << sNot << " + " <<"("<< velNot << " x " << time 
      <<")"  << " + " << "(1/2)" << acc << " x " << time << "^2" <<  endl;
    
    // Displays Result  
      cout << "S = " << fixed << setprecision(4) << red << Ms << " " << unit1 << "/"<< unit2 << resetColor << endl;
  }
  // Calculates Mv2
  else if( mChoice == "3")
  {   
    // Displays Equation
      cout << "\nV^2 is equal to " << pow(velNot,2) << " + " <<"2 x " << acc << "(" << sVar
      << " - " << sNot << ")" << endl;
    
    // Displays Result  
      cout << "V^2 = " << fixed << setprecision(4) << red << Mv2 << " " << unit1 << "/"<< unit2 << resetColor << endl;
  }
  // Calculates Mv
   else if( mChoice == "4")
  {   
    // Displays Equation
      cout << "\nV_bar is equal to " << "1/2( " << vel <<" + " << velNot << ")" << endl;
    
    // Displays Result  
      cout << "V_bar = " << fixed << setprecision(4) << red << Mv << " " << unit1 << "/"<< unit2 << resetColor << endl;
  }
  
}
// Calculates and displays force
void force(string unit1, string unit2, double mass, double acc)
{ 
  // Declares a variable to hold force, and sets the equation 
  double force;
  force = (mass * acc);

  // Displays equation w/variable values
  cout << "\n Force is calculated by multiplying mass by accerlation.\n" <<
  "\nTherefore the force is equal to " << mass << " " << unit1  << " x " 
  << acc << " "  << unit2 << " " <<endl ; 

  // Displays result with color
  cout << "The calculated force is " <<fixed <<setprecision(4) << red << force << " N" << resetColor << endl;

}
// Calculates and displays weight
void weight(string unit1, string unit2, double mass, double gravity)
{
  // Declares a variable to hold weight, and sets the equation 
  double weight;
  weight = (mass * gravity);

  // Displays equation w/variable values
  cout << "\n Weight is calculated by multiplying mass by gravity.\n" <<
  "\nTherefore the weight is equal to " << mass << " " << unit1  << " x " 
  << gravity << " "  << unit2 << " " <<endl ; 
  
  // Displays result with color
  cout << "The calculated weight is " <<fixed <<setprecision(4) << red << weight << " N" << resetColor << endl;

  cout << "\nsince weight is a force it is measured in newtons\n";

}
// Calculates and displays momentum
void momentum(string unit1, string unit2, double mass, double vel)
{
  // Declares a variable to hold momentum, and sets the equation 
  double momentum;
  momentum = (mass * vel);

  // Displays equation w/variable values
  cout << "\nmomentum is calculated by multiplying mass by velocity.\n" <<
  "\nTherefore the momentum is equal to " << mass << " " << unit1  << " x " 
  << vel << " "  << unit2 << " " <<endl ; 

 // Displays result with color
 cout << "The calculated momentum is " <<fixed <<setprecision(4) << red << momentum << resetColor << " " << unit1 << "x(" << unit2 << ")" << "." << endl;

}



void MenuSelection(string SelectedOption)
{
  // Variables used in functions
  double val1,val2,val3,velNot,vel,acc,time,sNot,sVar;
  string unit1,unit2;
  string mChoice;
   

  // if selected fully calculates velocity with units
  if(SelectedOption == "1")
    {
      // Takes and validates userinput for values used in velocity function
      cout << "\nPlease enter the value for ds\n";
      val1 = validateDouble(val1); 
      cout << "\nPlease enter the unit for ds\n";
      unit1 = validateString(unit1);
      cout << "\nPlease enter the value for dt\n";
      val2 = validateDouble(val2); 
      cout << "\nPlease enter the unit for dt\n";
      unit2 = validateString(unit2);
      
      velocity(unit1,unit2,val1,val2); // Calls velocity function
    }
   
   // if selected fully calculates accerlation with units
   else if(SelectedOption == "2" )
   {
      // Takes and validates userinput for values used in velocity function
      cout << "\nPlease enter the value for dv\n";
      val1 = validateDouble(val1); 
      cout << "\nPlease enter the unit for dv\n";
      unit1 = validateString(unit1);
      cout << "\nPlease enter the value for dt\n";
      val2 = validateDouble(val2); 
      cout << "\nPlease enter the unit for dt\n";
      unit2 = validateString(unit2);

      accerlation(unit1,unit2,val1,val2); // Calls accerlation function
   }
  
    // if selected fully calculates motions with units and multiple equations
    else if(SelectedOption == "3" )
   {
      // Displays motion menu with choices
      cout << "\nPlease select the motion equation you'd like to use\n";
      cout << "\nMOTION MENU" << endl; 
      cout << "1: Ma Calculator" <<endl; 
      cout << "2: Ms Calculator" << endl; 
      cout << "3: Mv2 Calculator" << endl; 
      cout << "4: Mv Calculator" <<endl; 
      cin >> mChoice;

          if(mChoice == "1")
      {   // Calculates Ma
          cout << "\nV is equal to V0 + at\n";
          cout << "Please enter your value for V0\n";
          velNot = validateDouble(velNot);  

          cout << "\nPlease enter your value for a\n";
          acc = validateDouble(acc); 

          cout << "\nPlease enter your value for t\n";
          time = validateDouble(time);
         
          cout << "\nPlease enter the final unit for x in (x/y) \n";
          unit1 = validateString(unit1);

          cout << "\nPlease enter the final unit for y in (x/y) \n";
          unit2 = validateString(unit2);

       }

            else if( mChoice == "2")
                { // Calculates Ms
                  cout << "\nS is equal to S0 + V0t + 1/2at^2\n";
                  cout << "Please enter your value for S0\n";
                  sNot = validateDouble(sNot);

                  cout << "\nPlease enter your value for V0\n";
                  velNot = validateDouble(velNot);

                  cout << "\nPlease enter your value for t\n";
                  time = validateDouble(time);

                  cout << "\nPlease enter your value for a\n";
                  acc = validateDouble(acc); 

                  cout << "\nPlease enter the final unit for x in (x/y) \n";
                  unit1 = validateString(unit1);

                  cout << "\nPlease enter the final unit for y in (x/y) \n";
                  unit2 = validateString(unit2);
                }

                else if( mChoice == "3")
                    {   // Calculates Mv2
                        cout << "\nV^2 is equal to V0^2 + 2a(s-s0)\n";
                        cout << "Please enter your value for V0\n";
                        velNot = validateDouble(velNot);

                        cout << "\nPlease enter your value for a\n";
                        acc = validateDouble(acc); 

                        cout << "Please enter your value for S\n";
                        sVar = validateDouble(sVar);

                        cout << "Please enter your value for S0\n";
                        sNot = validateDouble(sNot); 

                        cout << "\nPlease enter the final unit for x in (x/y) \n";
                        unit1 = validateString(unit1);

                        cout << "\nPlease enter the final unit for y in (x/y) \n";
                        unit2 = validateString(unit2);
                    }

                          else if( mChoice == "4")
                          {   // Calculates Mv
                              cout << "\nV_bar is equal to 1/2(v + v0)\n";
                              
                              cout << "Please enter your value for V\n";
                              vel = validateDouble(vel);

                              cout << "Please enter your value for V0\n";
                              velNot = validateDouble(velNot);

                              cout << "\nPlease enter the final unit for x in (x/y) \n";
                              unit1 = validateString(unit1);

                              cout << "\nPlease enter the final unit for y in (x/y) \n";
                              unit2 = validateString(unit2);
                          }
          // if choice != 1,2,3,4 then enter valid menu choice
          else if (mChoice != "1" || mChoice != "2" || mChoice != "3" || mChoice != "4")
          {
            cout << "\nPlease enter a valid menu choice(1-4)\n";
          }
                        
      // Function call
      motion(velNot, vel, acc, time, sNot, sVar, mChoice,unit1,unit2);
   }
   
   // if selected fully calculates force with units
   else if(SelectedOption == "4" )
   {
      // Takes and validates userinput for values used in velocity function
      cout << "\nPlease enter the value for mass\n";
      val1 = validateDouble(val1); 
      cout << "\nPlease enter the unit for mass\n";
      unit1 = validateString(unit1);
      cout << "\nPlease enter the value for accerlation\n";
      val2 = validateDouble(val2); 
      cout << "\nPlease enter the unit for accerlation\n";
      unit2 = validateString(unit2);
   
      force(unit1,unit2,val1,val2); // Calls force function

   }
   
   // if selected fully weight velocity with units
   else if(SelectedOption == "5" )
   {
      // Takes and validates userinput for values used in velocity function
      cout << "\nPlease enter the value for mass\n";
      val1 = validateDouble(val1); 
      cout << "\nPlease enter the unit for mass\n";
      unit1 = validateString(unit1);
      cout << "\nPlease enter the value for gravity\n";
      val2 = validateDouble(val2); 
      cout << "\nPlease enter the unit for gravity\n";
      unit2 = validateString(unit2);
   
      weight(unit1,unit2,val1,val2); // Calls weight function
   }
   
   // if selected fully calculates momentum with units
   else if(SelectedOption == "6" )
   {
      // Takes and validates userinput for values used in velocity function
      cout << "\nPlease enter the value for mass\n";
      val1 = validateDouble(val1); 
      cout << "\nPlease enter the unit for mass\n";
      unit1 = validateString(unit1);
      cout << "\nPlease enter the value for velocity\n";
      val2 = validateDouble(val2); 
      cout << "\nPlease enter the unit for velocity\n";
      unit2 = validateString(unit2);
   
      momentum(unit1,unit2,val1,val2); // Calls momentum function
   }
   
   // if selected clears the Screen
   else if(SelectedOption == "X" || SelectedOption == "x" )
   {
      string resetscreen = "\x1b[0m";
      cout << resetscreen; 
      cout << "\033[2J\033[1;1H";
      system("clear");
   }  
}

int main() 
{
  do
  {
    Menu(); //call a menu function  
  
     cin >> choice;  // Takes user input into choice.
    
      //input validation for menu choices
      if( choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "X" && choice != "x" && choice != "E" && choice != "e" )
      {
       cout << "\nPlease Enter a Valid Menu Option\n";
       }
      
      // Determines what calculation to run
      MenuSelection(choice);
  
  }while(choice != "e" && choice != "E"); //Uses E or e to exit the loop
  cout << "\nYou have exited the program." << endl;

  return 0;
}

/************* AUTHOR INFO **************/
// Name: Shahied Rustin
// Student No.: 230500226
// Course Title: Software Design 1 (SDN150S)
// Date: 13/04/2023
/************* HEADER FILES ***************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
/************* GLOBAL VARIABLES ************/
// state global variable if any
/******** FUNCTIONS (DECLARE/DEFINE) *********/
//typedef struct
//{ struct with bit-field (choose width length)
//type [member_name] : width
//.tag name;
/************* MAIN FUNCTION**************/
//Weekend Questions
// A series RLC circuit consist of a 40 uF (microfarad) capacitor is in series with 100 mH (millihenry) inductor, a 30 ohm resister, and a 15V AC signal with a frequency of 60Hz. 

// Write a C-program that request a user to enter the above details to perform the following;
// a. calculate the impedance
// b. calculate the RMS current in the circuit
// c. confirm that the voltages across the circuit is equal to the source voltage 
// d. determine how much power is consumed in the circuit
// e. calculate the resonant frequency of the circuit

// Note that each calculation should be done using seperate functions and called in the main.

//  START OF PROGRAM
const double pi = 3.141;
//User defined
    double capacitor, inductor, resistor, ACV, frequency;

//Impedance Start ---------------------------
double Xc(double c, double f){
    double Output = 1/(2*f*pi*c);
    return Output;
}

double Xl(double l, double f){
    double Output = 2*f*pi*l;
    return Output;
}

double Z(double Xl, double Xc, double r){
    double Output = sqrt(pow(r,2)+(pow(Xl,2)-pow(Xc,2)));
    return Output;
}
//Impedance End ------------------------------
//RMS current --------------------------------
double RMSI(double v, double z){
    double Output = v/z;
    return Output;

}

//Voltage confirmation
bool isVAuth(double r, double l, double c, double RMSI){
    double vR = RMSI*r;
    double vL = RMSI*l;
    double vC = RMSI*c;
    double Output = sqrt(pow(vR,2)+(pow(vL,2)+pow(vC,2)));
    
    if(Output == ACV){
        return true;
    } else {
        return false;
    }
}

//Power consumption --------------------------
double P(double i, double r){
    double Output = pow(i,2)*r;
    return Output;
}

//resonance frequency ------------------------
double resFr(double l, double c){
    double Output = 1/(2*pi*sqrt(l*c));
    return Output;
}

int main(){

    printf("A series RLC circuit consist of a capacitor in series with an inductor, a resistor, and an AC signal with a certain frequency.\n");

    printf("Enter the capacitance in microfarads : ");
    scanf("%lf", &capacitor);
    //convert to microfarads
    // capacitor = capacitor*1E-6;
    printf("Enter the inductance in millihenries : ");
    scanf("%lf", &inductor);
    //convert to millihenries
    // inductor = inductor*1E-3;
    printf("Enter the resistor in ohms : ");
    scanf("%lf", &resistor);
    printf("Enter the AC voltage in voltage : ");
    scanf("%lf", &ACV);
    printf("Enter the frequency in Hz: ");
    scanf("%lf", &frequency);

    printf("The reactive capacitance is %lf ohms\n", Xc(capacitor,frequency));

    printf("The reactive inductance is %lf ohms\n", Xl(inductor,frequency));

    printf("The Impedance is %lf ohms\n", Z(Xl(inductor,frequency),Xc(capacitor, frequency), resistor));

    printf("The RMS current is %lf Amps\n", RMSI(ACV,Z(Xl(inductor,frequency),Xc(capacitor, frequency), resistor)));

    printf("The voltage confirmation is %s \n", isVAuth(resistor, inductor, capacitor, RMSI(ACV,Z(Xl(inductor,frequency),Xc(capacitor, frequency), resistor))) ? "true" : "false");

    printf("The power consumption is %lf Watts\n", P(RMSI(ACV,Z(Xl(inductor,frequency),Xc(capacitor, frequency), resistor)),resistor));

    printf("The resonance frequency is %lf Hz\n", resFr(inductor, capacitor));

return 0;}
// END OF PROGRAM
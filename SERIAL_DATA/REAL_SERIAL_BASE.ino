/*
    REAL_SERIAL_BASE:
        [1] Can Calculate voltages being used and then applied
        [2] Calculate  Wave values from antennas, from Serial inputs.
        [3] display serial data / print serial data
  
  By. sSean Mm. jJ.
  DATE: JUNE 5th 2026
  CODE: to do basis analysis of serial data

*/

//TODO: move functions (relating functions) into these relating files
#include "LEDS.hpp"
#include "print_serial_data.hpp"
#include "serial_maths.hpp"
#include "store_serial_data.hpp"
//...

#define PIN_STATE HIGH;
//
#define ANALOG_INPUT_PIN_RX                 17      //READ RX @ <FREQ OF INPUTTED ANTENNA>
#define ANALOG_INPUT_PIN_TX                 18      //WRITE TX @ <FREQ OF INPUTTED ANTENNA>
#define ANALOG_INPUT_PIN_VIBRATION_DETECT   20      //READ pzo-electric vibration detector
#define ANALOG_INPUT_PIN_FLIPPER_ANTENNA    19      //READ RX @ <FREQ OF INPUTTED ANTENNA>
#define ANALOG_INPUT_PIN_ANTENNA_ROLL       15      //READ RX @ <FREQ OF INPUTTED ANTENNA>

//values used to sample and time data recived and receptions
const uint32_t           sample_rate             = 44100; //change if required based off capture speed specifications of input/output source 

//timing code - helped by chatGPT where stated
//??? where its from chatGPT but source of code is unkn
uintmax_t                microsec_calc_start     = 0;

//The setup routine runs once when you press reset:
//Serial.begin(n) = 460800 is max vaue of ESP32-wroom-32U1 for data intake
void setup() 
{
    start_up_LEDs(); //added after noticing - wanted it to show something symbolic so white-light
    Serial.begin(460800);
}

//loop through code to does:
  //A:
  //B:
  //C:
  //loop code to print results of inputted data thats been observed and used
void loop() 
{
    //get the observed current time in Microseconds
    uintmax_t now = micros();
    //function to return a bool value
    if (now - microsec_calc_start < (10000000 / sample_rate)) 
    {
      return;
    }
    microsec_calc_start = now;

//display data from pins
    double_t raw_input_A              = analogRead(ANALOG_INPUT_PIN_RX);
    double_t raw_input_v              = analogRead(ANALOG_INPUT_PIN_VIBRATION_DETECT); 
    double_t raw_input_B              = analogRead(ANALOG_INPUT_PIN_TX);//CAN BE USED WITH BASIC_RF_JAMMER
    double_t raw_input_antenna        = analogRead(ANALOG_INPUT_PIN_FLIPPER_ANTENNA);
    double_t raw_input_antenna_Roll   = analogRead(ANALOG_INPUT_PIN_ANTENNA_ROLL);

    //bug here, wont show on serial plot when jamming. wont fix for you. 
    //static int min = 5;                                     //its USE === ILLEGAL
    //static int max = 60;                                    //its USE === ILLEGAL
    //BASIC_RF_JAMMER(raw_input_B, min, max);Serial.flush();  //its USE === ILLEGAL

    signed short decimal_places = 7;
    print_raw_input_datas(raw_input_A, raw_input_B, raw_input_v, raw_input_antenna, raw_input_antenna_Roll, decimal_places);
    
    //FOR TESTING DATA EACH INPUT
    //println_raw_data(raw_input_A, decimal_places);
    //println_raw_data(raw_input_B, decimal_places);

    //display light depending if and when a change occurs in relation to results recived
    
    delayMicroseconds(1);
    prev_time = now;
}

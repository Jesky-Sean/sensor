/*
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

#define PIN_STATE HIGH;
//
#define ANALOG_INPUT_PIN_OASIS              17      //READ RX
#define ANALOG_INPUT_PIN_WTR                18      //WRITE TX
#define ANALOG_INPUT_PIN_VIBRATION_DETECT   20      //READ  vibration detector

//values used to sample and time data recived and receptions
const int           sample_rate             = 44000;

//timing code - helped by chatGPT where stated
//??? where its from chatGPT but source of code is unkn
unsigned long       microsec_calc_start     = 0;

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
    unsigned long now = micros();

    //function to return a bool value
    if (now - microsec_calc_start < (10000000 / sample_rate)) 
    {
      return;
    }
  
    microsec_calc_start = now;

//display data from pin A
    double_t raw_input_A = analogRead(ANALOG_INPUT_PIN_OASIS);
/*
    raw_input_A = normilize_raw_values(raw_input_A);
    signed short dec_places = 7;
    normilize_raw_values(raw_input_A);
    println_raw_data(raw_input_A, dec_places);
    light_ret(raw_input_A);
*/

    double_t raw_input_v = analogRead(ANALOG_INPUT_PIN_VIBRATION_DETECT);
    raw_input_v = normilize_raw_values(raw_input_v);

//display data from pin B
    //get input value read from pin thats been #defined [above]
    double_t raw_input_B = analogRead(ANALOG_INPUT_PIN_WTR);
    //return result of normilized values
    raw_input_B = normilize_raw_values(raw_input_B);
    //dec_places is how many decimal places to observe printed in terminal
    signed short dec_places = 7;
    normilize_raw_values(raw_input_B);
    //print the data after normilization
    println_raw_data(raw_input_B, dec_places);
    //display light depending if and when a change occurs in relation to results recived
    light_ret(raw_input_B);
    //comments are to be roughly the same as raw_input_A

//*/

    delayMicroseconds(1);
    prev_time = now;
}
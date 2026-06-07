unsigned long       prev_time               = 0;
const double_t      mid_value               = 512.000000;

//input a serial port to be read to calculate raw voltage
const double_t ret_raw_voltage(signed long& analog_reading_input_value) 
{
    double_t raw_input = (analogRead(analog_reading_input_value) * 5.000 / 4092.000);
    return raw_input;
}

//normalize values so its easier to read and understand
const double_t normilize_raw_values(double_t& serial_inputs) 
{
    serial_inputs = (serial_inputs - mid_value);    //chatGPT - ???
    serial_inputs = (serial_inputs / mid_value);    //chatGPT - ???

    return serial_inputs;
}


//time calabrated values [not used]
const double_t normilize_calabrated_raw_values(double_t& serial_inputs, unsigned long& time_as_of_now) 
{
    serial_inputs += (serial_inputs - mid_value);   //chatGPT - ???
    serial_inputs = (serial_inputs / mid_value);    //chatGPT - ???
     
    double_t calibrated_serial_values = serial_inputs + (prev_time / time_as_of_now);
    return calibrated_serial_values;
}

/*
//keep running [moving] averages of values inputted up to array_size_calculated
template <typename T> T calculate_average_values (T& input_values, const int& array_size_calculated) {
    input_values[array_size_calculated];
    const int   fnt_cnt                     = 2'000;        //  Final count to start avg. calculation
    float       avg                         = 0.000;        //  Calculate the avg. value 
    float       total_value                 = 0.000;        //  Total accumlicated value;
    int         raw_input_count_insofar     = 0;            //  True count of serial inputs recived


  raw_input_count_insofar += 1;
  total_value += input_values;
  if (fnt_cnt == raw_input_count_insofar && (array_size_calculated - 1) == raw_input_count_insofar) {
    avg = (total_value / raw_input_count_insofar);
    Serial.printf("average = %f\n", avg);
    raw_input_count_insofar = 0;
    total_value = 0;
  }
  return total_value;
}
*/
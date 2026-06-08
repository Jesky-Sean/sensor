//TODO: write function to display each color as req. by user
//LED to activate on ESP32 boards / Arduino Q
void start_up_LEDs()
{
    //digitalWrite(RGB_BUILTIN, HIGH);                  //  White
    //rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);   //  Red    
    rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 25, 42);   //  Blue
    //rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);   //  Green
}


//if within range of >= n display light accordingly
void light_ret(double_t& raw_input_ret)
{
    if (raw_input_ret >= 0.96 && raw_input_ret >= 1.0) {
        rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS);  //  Blue
    }
    else if (raw_input_ret >= 0.71 && raw_input_ret >= 0.95) {
        rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);  //  Red
    }
    else if (raw_input_ret >= 0.61 && raw_input_ret >= 0.70) {
        rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);  //  Green
    }
    else if (raw_input_ret >= 0.31 && raw_input_ret >= .60) {
        rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS);  //  Blue
        rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);  //  Red
    }
    else if (raw_input_ret >= 0.1 && raw_input_ret <= 0.30) {
        rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);  //  Green
        rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);  //  Red
    }
    else if (raw_input_ret >= 0.00 && raw_input_ret <= 0.09) {
        rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);  //  Red
        rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);  //  Green
    }
}
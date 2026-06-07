//pring data recived and inputted from serial pins into function
template <typename T> void println_raw_data(T& print_this_raw_data, signed short& decimal_places)
{
        Serial.println(print_this_raw_data, decimal_places);
}

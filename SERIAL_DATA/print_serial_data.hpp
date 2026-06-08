//pring data recived and inputted from serial pins into function
template <typename T> void println_raw_data(T& print_this_raw_data, signed short& decimal_places)
{
        Serial.println(print_this_raw_data, decimal_places);
}

//pring data recived and inputted from serial pins into function
template <typename T> void print_raw_data(T& print_this_raw_data, signed short& decimal_places)
{
        Serial.print(print_this_raw_data, decimal_places);
}
//pring data recived and inputted from serial pins into function
//TODO: PLACE IN A VECTOR/....
template <typename T> void print_raw_input_datas(T& print_raw_input_data_A, T& print_raw_input_data_B, T& print_raw_input_data_C, T& print_raw_input_data_D, T& print_raw_input_data_E, signed short& decimal_places)
{
        print_raw_data(print_raw_input_data_A, decimal_places);
        Serial.print(", ");
        print_raw_data(print_raw_input_data_B, decimal_places);
        Serial.print(", ");
        print_raw_data(print_raw_input_data_C, decimal_places);
        Serial.print(", ");
        print_raw_data(print_raw_input_data_D, decimal_places);
        Serial.print(", ");
        print_raw_data(print_raw_input_data_E, decimal_places);
        Serial.println();
}

template <typename T> void display_data(T& raw_data_outputs, signed short& dec_places){
        //get input value read from pin thats been #defined [above]
        //return result of normilized values
        raw_data_outputs = normilize_raw_values(raw_data_outputs);
        //dec_places is how many decimal places to observe printed in terminal
        //print the data after normilization
        normilize_raw_values(raw_data_outputs);
        println_raw_data(raw_data_outputs, dec_places);
}

//raw pin datas
double_t        original_S_Pin_A        = 0.000000;
double_t        original_S_pin_B        = 0.000000;


//original pin input/output
template <typename T> void store_original_input(T& original_input_A)
{
    original_S_Pin_A = original_input_A;  //from oasis
}


//capture original pins inputs/outputs
template <typename T> void store_original_input(T& original_raw_input_A, T& original_raw_input_B)
{
    original_S_Pin_A = original_raw_input_A;  //from oasis
    original_S_pin_B = original_raw_input_B;  //from water bottle
}

typedef float f32;

extern "C" f32 func_004A5C50(f32);

extern "C" void func_003E5D10(f32 *arg0) {
    f32 temp_f0 = *arg0;
    f32 buf[4];

    buf[0] = temp_f0;
    func_004A5C50(temp_f0);
}

extern float D_00769D24;
extern "C" void func_004758E8(float);

extern "C" void func_00421C80(float t) {
    if (t < 0.0f)
        t = 0.0f;
    if (t > 1.0f)
        t = 1.0f;
    D_00769D24 = t;
    func_004758E8(t);
}

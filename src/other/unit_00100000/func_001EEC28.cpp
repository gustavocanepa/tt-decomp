struct Obj_0023F9C0 {
    char pad[0x10];
    void *unk10;
};

extern "C" double func_004B4C18(float x);
extern "C" double func_004B4830(double a, double b);
extern "C" float func_004B4B10(double x);
extern "C" void func_002662F8(void *arg0, float arg1);

extern "C" void func_001EEC28(Obj_0023F9C0 *arg0, float arg1) {
    float r = func_004B4B10(func_004B4830(1.0, func_004B4C18(arg1 * 60.0f)));
    func_002662F8(arg0->unk10, r);
}

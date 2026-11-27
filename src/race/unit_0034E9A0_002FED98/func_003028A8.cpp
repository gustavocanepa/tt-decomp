struct Obj;
extern "C" int func_00301F08(Obj *);
extern "C" int func_003028A8(char *arg0) {
    float r;
    float a;
    float b;
    float s;
    int result;
    char *p;
    result = func_00301F08((Obj *)arg0);
    if (result) {
        p = arg0 + 0x104;
        result = 0;
        if (!(*(float *)(p + 0x4B0) < 1.0f)) {
            b = *(float *)(p + 0x55C);
            a = *(float *)(p + 0x560);
            s = b * b + a * a;
            __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(s));
            if (!(0.2777777612209321f < r)) {
                result = 1;
            }
        }
    }
    return result;
}

struct Obj;
extern "C" int func_00301F08(Obj *arg0);
extern "C" int func_003028A8(char *arg0);
extern "C" void func_00302920(char *arg0) {
    unsigned char *p;
    int t;
    if (func_00301F08((Obj *)arg0)) {
        p = (unsigned char *)(arg0 + 0x7E4);
        if (func_003028A8(arg0) == 0) {
            if (*p != 0) {
                *p = *p + 0xFF;
            }
        } else {
            t = *p + 1;
            if (t >= 0x23) {
                t = 0x22;
            }
            *p = t;
        }
    }
}

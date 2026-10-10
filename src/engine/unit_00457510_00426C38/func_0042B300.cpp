extern "C" void *D_00585E88;
extern "C" void *D_00585E8C;
extern "C" int D_00585E90;
extern "C" void func_004A45D0(void *p);

extern "C" void func_0042B300(void) {
    if (D_00585E88) {
        void *p = D_00585E88;
        D_00585E88 = 0;
        func_004A45D0(p);
        p = D_00585E8C;
        D_00585E8C = 0;
        func_004A45D0(p);
        D_00585E90 = 0;
    }
}

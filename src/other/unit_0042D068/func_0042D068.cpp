extern "C" int D_00585F10;
extern "C" int D_00585F1C;
extern "C" int D_00585F18;

extern "C" void func_0042B5E8(void);
extern "C" void func_0042CDE8(void);

extern "C" void func_0042D068(void) {
    switch (D_00585F10) {
    case 1:
        func_0042B5E8();
        break;
    case 2:
        func_0042CDE8();
        break;
    }
    D_00585F10 = 0;
    D_00585F18 = -1;
    D_00585F1C = -1;
}

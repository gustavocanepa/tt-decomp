extern "C" int D_00585F10;
extern "C" int D_00585F1C;
extern "C" int D_00585F18;

extern "C" void func_0042B5C8(void);
extern "C" void func_0042CDA8(void);

extern "C" void func_0042CFF8(void) {
    switch (D_00585F10) {
    case 1:
        func_0042B5C8();
        break;
    case 2:
        func_0042CDA8();
        break;
    }
    D_00585F10 = 0;
    D_00585F18 = -1;
    D_00585F1C = -1;
}

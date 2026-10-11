extern "C" void func_004A4D68(void *m);
extern "C" void func_004A4DD8(void *m);
extern "C" void func_0042B3C0(float v);
extern "C" void func_0042C900(float v);

extern char D_0076A058[];
extern int D_00585F10;
extern float D_00585F14;
extern float D_00585F20;

extern "C" float func_0042D1D0(float v)
{
    func_004A4D68(D_0076A058);
    float old = D_00585F14;
    D_00585F14 = v;
    v *= D_00585F20;
    switch (D_00585F10) {
    case 1:
        func_0042B3C0(v);
        break;
    case 2:
        func_0042C900(v);
        break;
    }
    func_004A4DD8(D_0076A058);
    return old;
}

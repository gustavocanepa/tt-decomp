/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { int f[11]; };
extern "C" Rec D_00585720, D_00585750, D_00585780, D_005857B0;
extern "C" void func_003FFA40(Rec *out, int a, int b) {
    int sel = 0;
    if (a) sel += 1;
    if (b) sel += 2;
    Rec *src = &D_00585720;
    switch (sel) {
    case 0: break;
    case 1: src = &D_00585750; break;
    case 2: src = &D_00585780; break;
    case 3: src = &D_005857B0; break;
    }
    *out = *src;
}

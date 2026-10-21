struct O { char p[0x10]; char f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f1A, f1B, f1C, f1D, f1E, f1F, f20, f21, f22, f23, f24, f25; };
extern "C" void func_00404728(O *o, int a) {
    int v = 1;
    if (a) v = a;
    o->f10 = v;
    o->f11 = 0;
    o->f12 = 3;
    o->f13 = 4;
    o->f14 = 13;
    o->f15 = 14;
    o->f16 = 16;
    o->f17 = 12;
    o->f18 = 7;
    o->f19 = 6;
    o->f1A = -1;
    o->f1B = -1;
    o->f1C = 10;
    o->f1D = 8;
    o->f1E = -1;
    o->f1F = 15;
    o->f20 = 2;
    o->f21 = 3;
    o->f22 = 17;
    o->f23 = 9;
    o->f24 = 3;
    o->f25 = 2;
    switch (v) {
    case 2:
        o->f24 = v;
        o->f25 = 3;
        break;
    case 3:
        o->f24 = 6;
        o->f25 = 7;
        break;
    }
}

struct S {
    char p0[0xC4];
    int f_c4;
    char p1[0xC8 - 0xC8];
    int f_c8;
    char p2[0xD4 - 0xCC];
    int f_d4;
    int f_d8;
    float f_dc[4];
};

extern "C" int func_004C9A38(int arg0, int arg1);
extern "C" int func_004C99C0(int arg0, int arg1);
extern "C" float func_003EB720(float arg0);
extern "C" int D_005855A0[];

extern "C" void func_003EB7C8(S *arg0, float *arg1) {
    int n;
    int r;
    int flags;

    arg0->f_d4 = arg0->f_d8;
    flags = 0;
    if (func_004C9A38(arg0->f_c8, 0x1A) != 0)
        flags |= 1;
    if (func_004C9A38(arg0->f_c8, 0x1B) != 0)
        flags |= 2;
    if (func_004C9A38(arg0->f_c8, 0x18) != 0)
        flags |= 0x10;
    if (func_004C9A38(arg0->f_c8, 0x19) != 0)
        flags |= 0x20;
    if (func_004C9A38(arg0->f_c8, 0x14) != 0)
        flags |= 0x40;
    if (func_004C9A38(arg0->f_c8, 0x16) != 0)
        flags |= 0x80;
    if (func_004C9A38(arg0->f_c8, 0x17) != 0)
        flags |= 0x100;
    if (func_004C9A38(arg0->f_c8, 0x15) != 0)
        flags |= 0x200;
    if (func_004C9A38(arg0->f_c8, 0x1C) != 0)
        flags |= 0x800;
    if (func_004C9A38(arg0->f_c8, 0x1F) != 0)
        flags |= 0x800;
    if (func_004C9A38(arg0->f_c8, 0x2C) != 0)
        flags |= 0x800;
    if (func_004C9A38(arg0->f_c8, 0x2F) != 0)
        flags |= 0x800;
    if (func_004C9A38(arg0->f_c8, 0x1E) != 0)
        flags |= 0x400;
    if (func_004C9A38(arg0->f_c8, 0x1D) != 0)
        flags |= 0x400;
    arg0->f_d8 = flags;
    if (arg1 != 0) {
        arg0->f_d4 = flags;
    }
    for (n = 0; n < 4; n++) {
        int r2 = func_004C99C0(arg0->f_c4, D_005855A0[n]);
        arg0->f_dc[n] = func_003EB720((float)r2);
    }
}

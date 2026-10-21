typedef int s32;
typedef float f32;

extern "C" s32 func_002F04D8(void *arg0, s32 arg1);
extern "C" s32 func_00305C80(void *arg0, void *arg1, s32 arg2);
extern "C" void RaceDisplayEventBase__put(void *o, void *t);
extern "C" void func_00358D38(void *arg0);
extern "C" f32 func_00439488(void *p, f32 x);
extern char D_005865D0[];

extern "C" void func_00306050(void *arg0, s32 arg1, f32 fparg0) {
    s32 buf[4];
    char *temp_s1;
    s32 temp_a1;
    s32 r;
    unsigned char *w;

    w = (unsigned char *)((char *)func_002F04D8(arg0, arg1) + 0x104);
    if (w[0x461] == 0 && w[0x64E] == 0) {
        temp_s1 = *(char **)arg0;
        r = func_00305C80(temp_s1, arg0, func_002F04D8(arg0, arg1));
        temp_a1 = arg1 * 4;
        if (r == 0) {
            char *v60 = *(char **)(temp_s1 + 0x60);
            s32 v8 = *(s32 *)(v60 + 8);
            char *el = *(char **)(temp_a1 + v8);
            *(f32 *)(el + 0x5458) = fparg0;
        }
        if (*(s32 *)(temp_s1 + 0xDC) == 0) {
            func_00358D38(buf);
            buf[0] = arg1;
            *(f32 *)&buf[2] = func_00439488(D_005865D0, fparg0);
            RaceDisplayEventBase__put(buf, temp_s1);
        }
    }
}

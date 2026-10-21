extern char D_0057C070;
extern char D_005F0AD0;
extern char D_00293310;
extern char D_00293338;
extern char D_00293360;

typedef int s32;

extern "C" void func_00297858(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5);

extern "C" void func_00295B70(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1) {
        func_00297858(&D_0057C070, &D_005F0AD0, 0x24, &D_00293310, &D_00293338, &D_00293360);
    }
}

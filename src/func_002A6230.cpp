extern char D_0057C230;
extern char D_005F1230;
extern char D_002A28B8;
extern char D_002A28E0;
extern char D_002A2908;

typedef int s32;

extern "C" void func_00297858(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5);

extern "C" void func_002A6230(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1) {
        func_00297858(&D_0057C230, &D_005F1230, 0x2C, &D_002A28B8, &D_002A28E0, &D_002A2908);
    }
}

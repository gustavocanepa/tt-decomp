extern char D_00579DB0;
extern char D_005E5BD8;
extern char D_00191428;
extern char D_00191450;
extern char D_00191478;

typedef int s32;

extern "C" void func_00297858(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5);

extern "C" void func_00191E00(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1) {
        func_00297858(&D_00579DB0, &D_005E5BD8, 0x10, &D_00191428, &D_00191450, &D_00191478);
    }
}

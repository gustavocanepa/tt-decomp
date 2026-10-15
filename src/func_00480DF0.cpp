typedef int s32;

extern "C" char D_0076FCC0[];
extern "C" char D_0076FCE0[];
extern "C" char D_0076FD00[];
extern "C" char D_0076FF00[];

extern "C" void func_0056EDA0(void *a, void *b, s32 c, s32 d);
extern "C" void func_0056EDE8(void *a, void *b, s32 c, s32 d);
extern "C" void func_0056EE30(void *arg0, s32 arg1);
extern "C" void func_0056EE88(void *arg0, s32 arg1);

extern "C" void func_00480DF0(s32 init, s32 prio) {
    if (prio == 0xFFFF && init == 1)
        func_0056EDA0(D_0076FCC0, D_0076FD00, 0x200, 0x10);
    if (prio == 0xFFFF && init == 1)
        func_0056EDE8(D_0076FCE0, D_0076FF00, 0x800, 0x40);
    if (prio == 0xFFFF && init == 0)
        func_0056EE30(D_0076FCE0, 2);
    if (prio == 0xFFFF && init == 0)
        func_0056EE88(D_0076FCC0, 2);
}

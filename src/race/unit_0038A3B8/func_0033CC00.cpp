extern "C" void func_00372AC8(void *obj);
extern "C" void func_00372B00(void *obj, int flags);
extern "C" void func_004AC338(void *obj, const char *name);
extern "C" char D_00767C80[];
extern "C" char D_00767CF0[];
extern "C" char D_005F3BD0[];

extern "C" void func_0033CC00(int init, int prio)
{
    if (prio == 0xFFFF && init == 1)
        func_00372AC8(D_00767C80);
    if (prio == 0xFFFF && init == 1)
        func_004AC338(D_00767CF0, D_005F3BD0);
    if (prio == 0xFFFF && init == 0)
        func_00372B00(D_00767C80, 2);
}

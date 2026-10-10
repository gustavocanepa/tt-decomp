struct Arena {
    char pad[0x18];
    void *vtable;
    int pad1C;
    char member[0x10];
};

extern "C" Arena D_00584758;
extern "C" char D_00584778[];
extern "C" char D_005CF678[];
extern "C" void func_0042F9C0(Arena *a);
extern "C" void func_0042F960(Arena *a, int flags);
extern "C" void func_00388C30(void *m);

extern "C" void func_00389008(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        func_0042F9C0(&D_00584758);
        D_00584758.vtable = D_005CF678;
    }
    if (prio == 0xFFFF && init == 1)
        func_00388C30(D_00584778);
    if (prio == 0xFFFF && init == 0)
        func_0042F960(&D_00584758, 0);
}

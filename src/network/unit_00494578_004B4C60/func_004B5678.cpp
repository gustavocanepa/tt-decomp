extern char D_00773E68;

struct S_86C8E0 {
    char pad[0x30];
    char f0;
    char f1;
    char f2;
    char f3;
    char f4;
    char f5;
};
extern S_86C8E0 D_00773E70;

extern "C" void func_004A4930(void *arg0);
extern "C" void func_004A4970(void *arg0);
extern "C" void func_004AEB30(void *arg0);

extern "C" void func_004B5678(void) {
    void * volatile sp0 = &D_00773E68;
    func_004A4930(&D_00773E68);

    D_00773E70.f0 = 1;
    D_00773E70.f4 = 1;
    D_00773E70.f1 = 0;
    D_00773E70.f3 = 0;
    D_00773E70.f5 = 0;

    func_004A4970(sp0);
    func_004AEB30(&D_00773E70);
}

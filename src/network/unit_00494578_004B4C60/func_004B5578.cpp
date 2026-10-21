/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
struct G {
    char pad0[0x30];
    char b30, b31, b32, b33, b34, b35;
    char pad36[4];
    char name[0x100];
    s32 f13C;
    char b140;
};
extern char D_00773E68[];
extern G D_00773E70;
extern "C" void func_004AEB30(void *);
extern "C" void func_004A4930(void *);
extern "C" void func_004A4970(void *);
extern "C" char *func_004F7B74(char *, const char *);
struct Guard {
    void *p;
    Guard(void *q) : p(q) { func_004A4930(q); }
    ~Guard() { func_004A4970(p); }
};
extern "C" void func_004B5578(const char *name, s32 arg1, s32 arg2) {
    {
        Guard g(D_00773E68);
        D_00773E70.f13C = arg2;
        D_00773E70.b30 = 1;
        D_00773E70.b31 = 1;
        D_00773E70.b32 = 0;
        D_00773E70.b33 = 0;
        D_00773E70.b34 = 0;
        D_00773E70.b35 = 0;
        func_004F7B74(D_00773E70.name, name);
        D_00773E70.b140 = arg1;
    }
    func_004AEB30(&D_00773E70);
}

typedef int s32;
struct Base {
    char pad[0x64];
    virtual void v0(s32);
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct Obj : public Base { char pad2[0x100]; };
extern "C" {
void func_00102820(char *);
void func_004AE9F0(void *, s32);
void func_004A45D0(s32);
void func_0050E1A8(s32);
}
extern Obj *D_00579318;
extern char *D_0057931C;
extern s32 D_00579314;
extern "C" void func_001033B8(void) {
    if (D_00579318) {
        D_00579318->v2();
        D_00579318->v3();
        D_00579318->v0(2);
        D_00579318 = 0;
        func_00102820(D_0057931C);
        char *p = D_0057931C;
        if (p) {
            func_004AE9F0(p + 0x38, 2);
            func_004AE9F0(p + 8, 2);
            func_0050E1A8((s32)p);
        }
        D_0057931C = 0;
    }
    if (D_00579314) {
        func_004A45D0(D_00579314);
        D_00579314 = 0;
    }
}

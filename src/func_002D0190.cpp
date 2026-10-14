typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x14];
    s32 unk14;
    char pad18[0x18];
    s32 unk30;
};

extern "C" void func_002CFA98(Obj *arg0, f32 arg1);
extern "C" s32 func_002CFE40(void);
extern "C" void func_0042D488(s32 arg0, void *arg1, s32 arg2, f32 arg3);

extern "C" void func_002D0190(Obj *arg0, void *arg1, s32 arg2, f32 fparg0) {
    f32 t;
    if (func_002CFE40() != 0) {
        t = fparg0;
    } else {
        t = 0.0f;
    }
    func_0042D488(0xC, arg1, arg2, t);
    arg0->unk14 = 0;
    arg0->unk30 = 1;
    func_002CFA98(arg0, fparg0);
}

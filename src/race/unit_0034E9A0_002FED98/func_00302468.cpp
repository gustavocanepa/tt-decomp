typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Obj {
    char pad0[0x7E7];
    s8 unk78B;
};

struct S;

extern "C" s32 func_00301F08(Obj *arg0);
extern "C" s32 func_00301F68(Obj *arg0);
extern "C" u32 func_00301F78(S *arg0);

extern char D_005834B8[];

extern "C" s32 func_00302468(Obj *arg0, f32 *arg1) {
    s32 r;
    s32 off;

    r = func_00301F08(arg0);
    if (r != 0) {
        s8 t = arg0->unk78B;
        if (t < 0x19) {
            char *tbl = D_005834B8;
            *arg1 = (f32)(0x18 - t) / 24.0f;
            off = func_00301F68(arg0);
            r = *(u8 *)(tbl + off);
        } else {
            char *tbl = D_005834B8;
            *arg1 = (f32)(t - 0x18) / 12.0f;
            off = (s32)func_00301F78((S *)arg0);
            r = *(u8 *)(tbl + off);
        }
    }
    return r;
}

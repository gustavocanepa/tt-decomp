typedef int s32;
typedef float f32;

struct Blk40 {
    char b[36];
    s32 w;
};

struct Obj {
    s32 w00;
    Blk40 blk;
    s32 w2C;
    s32 w30;
    s32 w34;
    s32 w38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    f32 f4C;
    f32 f50;
};

extern "C" f32 func_004B2B08(f32 fparg0);

extern "C" void func_003EBD90(Obj *arg0, Blk40 *arg1, s32 arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    arg0->blk = *arg1;
    arg0->w3C = 1;
    arg0->w2C = (s32)(fparg0 * 0x1.ep+5f);
    arg0->w30 = (s32)(fparg1 * 0x1.ep+5f);
    arg0->w44 = arg2;
    arg0->w48 = arg3;
    arg0->w00 = 0;
    arg0->w38 = 0;
    arg0->w40 = 0;
    arg0->w34 = 0;
    arg0->f4C = func_004B2B08(0x1.0p+0f);
    arg0->f50 = func_004B2B08(0x1.0p+0f);
}

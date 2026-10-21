typedef int s32;

struct Self1CA7B0 {
    char pad0[0x3C];
    s32 f3c;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4c;
    s32 f50;
    s32 f54;
};

extern "C" s32 func_001A6AA8(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" void func_004A5618(void *arg0);
extern "C" void *func_004A56C8(s32 *arg0, s32 *arg1, s32 arg2);
extern char D_005E71C0[];
extern char D_001A65A0[];

extern "C" s32 func_001A68B0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Self1CA7B0 *self = (Self1CA7B0 *)arg0;
    if (self->f54 == 0) {
        return (s32)D_005E71C0;
    }
    s32 r = func_001A6AA8(arg0, arg1, arg2, arg3);
    if (r != 0) {
        return r;
    }
    self->f48 = arg3;
    self->f4c = arg1;
    self->f50 = arg2;
    s32 buf[8];
    s32 *p10 = &buf[4];
    buf[0] = (s32)D_001A65A0;
    buf[1] = (s32)arg0;
    *p10 = 0;
    buf[5] = 0x4000;
    s32 *t = (s32 *)func_004A56C8(buf, p10, 0);
    t[0x10] = 1;
    self->f3c = 1;
    self->f44 = 0;
    self->f40 = 0;
    func_004A5618(t);
    return 0;
}

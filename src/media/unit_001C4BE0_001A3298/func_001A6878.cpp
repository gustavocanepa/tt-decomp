/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Self778 {
    char pad0[0x3C];
    volatile s32 f3c;
};

extern char D_005E71D0[];
extern "C" s32 func_001A68B0(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_001A6878(void *arg0, s32 arg1, s32 arg2) {
    Self778 *self = (Self778 *)arg0;
    if (self->f3c != 0) {
        return (s32)D_005E71D0;
    }
    return func_001A68B0(arg0, arg1, arg2, 1);
}

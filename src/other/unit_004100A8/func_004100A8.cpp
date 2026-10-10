typedef int s32;

extern s32 D_00585C1C;
extern "C" s32 func_0040FFE8(void *, s32 *);
extern "C" s32 func_00411D78(s32, s32);
extern "C" void func_004F7B74(void *, s32);

extern "C" void func_004100A8(void *self, void *out) {
    s32 t[4];
    if (func_0040FFE8(self, t)) {
        func_004F7B74(out, func_00411D78(D_00585C1C, t[0]));
    }
}

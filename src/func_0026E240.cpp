typedef int s32;
typedef float f32;

extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_0029CF48(void *arg0, s32 arg1);
extern "C" s32 func_0029E9F0(s32 arg0);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);
extern "C" f32 func_004B2B08(f32 fparg0);

extern "C" void MRandom__getValue(s32 *arg0, s32 unused1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 s0;
    s32 s1;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 2) {
        func_0029CF48(buf0, arg3);
        s1 = func_0029E9F0(buf0[0]);
        func_0029CEF0(buf0, 2);
        func_0029CF48(buf0, arg3 + 4);
        s0 = func_0029E9F0(buf0[0]);
        func_0029CEF0(buf0, 2);
        s0 = s0 - s1;
        f32 r = func_004B2B08((f32)s0);
        s32 sum = (s32)(r + (f32)s1);
        func_0029EA18(buf0, sum);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(buf0, 2);
    }
}

typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_003F8A40(s32 a0, s32 a1, const char *a2, u8 a3, s32 t0, s32 t1);

extern "C" s32 func_003F8BA8(s32 arg0, s32 arg1, u8 arg2) {
    return func_003F8A40(arg0, arg1, "%s%04d", arg2, 1, *(s32 *)((char *)arg0 + 0xC04));
}

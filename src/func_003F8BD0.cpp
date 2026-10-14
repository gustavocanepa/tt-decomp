typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_003F8A40(s32 arg0, const char *arg1, const char *arg2, u8 arg3, s32 arg4, s32 arg5);

extern "C" s32 func_003F8BD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_003F8A40(arg0, (const char *)"Q212GranTurismo413UpdateManager", "Q212GranTurismo413GameData", (u8)(arg1 & 0xFF), arg2, arg3);
}

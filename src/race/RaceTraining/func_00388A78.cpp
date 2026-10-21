/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" s32 RaceBase__getLicenseSubNumber(s32);
extern "C" s32 func_0033CAB8(s32);
extern "C" s32 func_0040EE28(s32);
extern "C" s32 func_00388A78(void *arg0, s32 *arg1) {
    s32 *mode = (s32 *)((char *)arg0 + 0xE2C);
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    *arg1 = -1;
    var_v0 = *mode;
    if ((var_v0 ^ 3) == 0) {
        temp_v0 = func_0040EE28(*(s32 *)((char *)*(void **)((char *)arg0 + 0x6C) + 0x70));
        temp_v0_2 = func_0033CAB8(temp_v0);
        if (temp_v0_2 == 0) {
            return *mode;
        }
        *arg1 = RaceBase__getLicenseSubNumber(temp_v0);
        var_v0 = temp_v0_2;
        return var_v0;
    }
    return var_v0;
}

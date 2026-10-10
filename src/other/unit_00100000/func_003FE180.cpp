typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_004C0430(void);

extern "C" s32 func_003FE180(void) {
    return (u32)(func_004C0430() - 1) < 2U;
}

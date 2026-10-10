typedef int s32;

typedef s32 (*FnPtr)(void);
extern FnPtr D_005A4798;

extern "C" s32 func_00509778(void) {
    return D_005A4798() + 4;
}

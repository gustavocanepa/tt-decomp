typedef unsigned char u8;
typedef int s32;

extern "C" s32 func_002E7CF8(s32 arg0);

extern "C" void func_005524B0(s32 arg0, u8 *arg1) {
    *arg1 += func_002E7CF8(arg0);
}

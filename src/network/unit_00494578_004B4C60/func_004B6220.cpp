/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct S { s32 f0; char p4[0x3C]; void *f40; char p44[0x3C]; char f80[4]; };
extern s32 D_00598334;
extern char D_00774100[];
extern S D_00774200;
extern "C" void func_004F45B8(void *, s32);
extern "C" s32 func_004F45D8(void *, s32, s32, s32, s32);
extern "C" s32 func_004F4138(s32, s32);
extern "C" void func_004F4348(s32);
extern "C" void func_004B6220(void) {
    s32 *g = &D_00598334;
    *g = func_004F4138(1, 1);
    func_004F45B8(D_00774100, 0x50434456);
    func_004F45B8(&D_00774200, 0x50636476);
    func_004F4348(D_00774200.f0);
    D_00774200.f40 = D_00774200.f80;
    func_004F45D8(&D_00774200, 0, 0, 0, 0);
}

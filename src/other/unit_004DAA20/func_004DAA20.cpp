/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_005A0BCA;
extern "C" s32 func_004DA960(void);
extern "C" void func_004FA8D0(u32 *);

extern "C" s32 func_004DAA20(void) {
    u32 cfg[4];
    if (func_004DA960() != 0)
        return D_005A0BCA;
    func_004FA8D0(cfg);
    return (cfg[0] >> 1) & 3;
}

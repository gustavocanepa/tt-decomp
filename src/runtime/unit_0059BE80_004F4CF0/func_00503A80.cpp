/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;

extern s32 D_005A3188[];
extern s32 D_005A3180;
extern char D_005039F8[];
extern char D_005039C0[];

extern "C" s32 func_00503A38(s32, s32, s32);
extern "C" void func_00503B80(s32, s32);

extern "C" void func_00503A80(void) {
    s32 *g = D_005A3188;
    s32 s3;
    s32 s2;
    u32 s1;
    u32 s0;

    func_00503B80(g[0], g[1]);
    func_00503B80(g[2], g[3]);

    s3 = func_00503A38(0x80000000, 0x80080000, (s32)D_005039F8);
    s1 = (u32)s3 - 0x20C;
    s2 = func_00503A38(0x80000000, 0x80080000, (s32)D_005039C0);
    s0 = (u32)s2 - 0x168;

    if (s1 != s0) {
        do {
            if (s1 < s0) {
                s3 = func_00503A38(s3 + 4, 0x80080000, (s32)D_005039F8);
                s1 = (u32)s3 - 0x20C;
            } else {
                s2 = func_00503A38(s2 + 4, 0x80080000, (s32)D_005039C0);
                s0 = (u32)s2 - 0x168;
            }
        } while (s1 != s0);
    }

    D_005A3180 = (s32)s1;
}

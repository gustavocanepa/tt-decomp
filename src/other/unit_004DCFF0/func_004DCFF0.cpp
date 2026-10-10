/* compiler: ee-gcc2.9-991111 */
typedef int s32;

struct Ent { s32 a, b, c, d; char pad[0x324]; };
extern s32 D_005A0D10;
extern Ent D_007869D0[16];

extern "C" s32 func_004DCFF0(void) {
    s32 i;
    D_005A0D10 = 1;
    for (i = 0; i < 16; i++) {
        D_007869D0[i].a = 0;
        D_007869D0[i].b = 0;
        D_007869D0[i].c = 0;
        D_007869D0[i].d = 0;
    }
    return 1;
}

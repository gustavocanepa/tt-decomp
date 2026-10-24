/* compiler: ee-gcc2.9-991111 */
typedef int s32;
extern s32 func_004FA840(s32);
extern s32 func_004FA870(s32);
extern s32 func_004FE530(void *, s32, s32, void *, s32, void *, s32, void *, s32);
extern char D_00782AC0[];
extern char D_00782B40[];
extern char D_00784640[];
extern char D_005A0BF4[];
extern char D_005A0BF0[];
extern char D_004DB328[];

s32 func_004DB338(s32 arg0) {
    char *s1 = D_00782AC0;
    s32 saved = arg0;
    if (*(s32 *)(s1 + 0x24) == 0) {
        return -0x64;
    }
    if (func_004FA870(*(s32 *)D_005A0BF4) < 0) {
        return -0xC8;
    }
    {
    char *a3 = D_00782B40;
    *(s32 *)(a3 + 0x14) = saved;
    if (func_004FE530(s1, 0x14, 1, a3, 0x30, D_00784640 - 0x5C0, 4, D_004DB328, 0) != 0) {
        func_004FA840(*(s32 *)D_005A0BF4);
        return -0x5B;
    }
    }
    *(s32 *)D_005A0BF0 = 0x14;
    return 0;
}

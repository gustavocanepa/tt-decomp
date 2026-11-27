/* compiler: ee-gcc2.9-991111 */
typedef int s32;

struct G {
    char pad[0x24];
    s32 f24;
};

extern s32 D_005A3174;
extern struct G D_0078F700;
extern char D_0078F500[];
extern char D_0078F728[];

extern s32 func_004FE350(struct G *, s32, s32);
extern s32 func_004FE530(struct G *, s32, s32, s32, s32, char *, s32, s32, s32);

s32 func_00502898(int unused0) {
    s32 w;
    s32 r;

    if (D_005A3174 < 0) {
        for (;;) {
            r = func_004FE350(&D_0078F700, 0x80000006, 0);
            if (r < 0) {
                return -1;
            }
            if (D_0078F700.f24 != 0) {
                D_005A3174 = 0;
                if (func_004FE530(&D_0078F700, 0xFF, 0, 0, 0, D_0078F500, 4, 0, 0) < 0) {
                    return 0xFFFEFFFF;
                }
                __builtin_memcpy(D_0078F728, D_0078F500, 4);
                return 0;
            }
            w = 0x100000;
            do {
                w = w - 1;
            } while (w != -1);
        }
    }
    return 0;
}

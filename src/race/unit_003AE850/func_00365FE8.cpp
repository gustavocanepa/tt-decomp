typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

extern struct Pair D_005840C8[];
extern char D_00584428[];
extern s32 D_00584418;
extern s32 D_00584430;

extern "C" s32 func_0044CD98(s32, s32, s32);

extern "C" void func_00365FE8(void) {
    struct Pair *p = D_005840C8;
    s32 n = 0x69;
    do {
        s32 a2 = p->b;
        n--;
        s32 idx = p->a;
        p++;
        ((s32 *)D_00584418)[idx] = func_0044CD98((s32)D_00584428, D_00584430, a2);
    } while (n >= 0);
}

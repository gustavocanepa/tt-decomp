/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    int a, b, c;
    char pad0[0x28];
    int tab[8][8];
    char pad[0x734 - 0x134];
    int z[3];
    char pad2[0x84C - 0x740];
    int tag;
};
extern char D_005DA250[];
extern "C" float func_004A5C50(float);
extern "C" void func_0045BDE0(Obj *o) {
    int i, j;
    o->a = 0;
    o->b = 0;
    o->c = 0;
    o->tag = (int)D_005DA250;
    int *base = (int *)o + 1;
    for (j = 2; j >= 0; j--) o->z[j] = 0;
    int *col = base;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            col[j + 12] = (int)(func_004A5C50((2.0f * (float)j + 1.0f) * (float)i * 0x1.921fb4p-3f) * 32768.0f);
        col += 8;
    }
}

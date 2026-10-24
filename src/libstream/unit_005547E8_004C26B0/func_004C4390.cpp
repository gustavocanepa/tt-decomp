/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Table { char pad[0xC]; u16 *offsets; };
extern "C" void *func_004C4390(Table *t, int idx) {
    u16 *tab = t->offsets;
    if (tab == 0) return 0;
    if (*tab < idx) return 0;
    return (char *)tab + (tab[idx + 1] & 0xFFFE);
}

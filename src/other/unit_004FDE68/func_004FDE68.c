/* compiler: ee-gcc2.9-991111 */
typedef int s32;

struct Item {
    char pad0[0x40];
};

struct Arr {
    char pad0[0x1C];
    struct Item *items;
    s32 count;
};

extern struct Item *func_004FDE38(struct Arr *a, s32 i);

struct Item *func_004FDE68(struct Arr *a, s32 i) {
    if (i < 0 || i >= a->count) {
        return func_004FDE38(a, i);
    }
    return &a->items[i];
}

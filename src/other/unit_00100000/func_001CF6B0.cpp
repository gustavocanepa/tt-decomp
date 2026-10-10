typedef int s32;

struct Item {
    char pad0[0x30];
};

struct Obj {
    char pad0[0x10];
    s32 count;
    Item *items;
    char pad18[0x8];
    char ctx[4];
};

extern "C" void func_001CF548(Item *item, s32 arg, char *ctx, s32 extra);

extern "C" void func_001CF6B0(Obj *self, s32 index, s32 arg, s32 extra) {
    if (index >= self->count) {
        index = self->count - 1;
    }
    func_001CF548(&self->items[index], arg, self->ctx, extra);
}

struct Item {
    int unk0;
    int a;
    int b;
};

struct Obj {
    char pad0[0x4C];
    int (*callback)(void *ctx, int a, int b);
    void *ctx;
};

extern "C" Item *func_001A5410(int id);

extern "C" int func_001A6450(Obj *self, int id) {
    Item *item = func_001A5410(id);
    if (!item)
        return -300;
    if (!self->callback)
        return -300;
    return self->callback(self->ctx, item->a, item->b) ? -200 : -300;
}

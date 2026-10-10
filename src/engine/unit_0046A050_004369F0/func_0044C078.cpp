struct Obj {
    char pad0[0x64];
    int dirty;
    char pad68[0x98 - 0x68];
    int hidden;
};

extern "C" void func_0043C8D8(void *ctx, Obj *obj);
extern "C" void func_0043C8E8(void *ctx, Obj *obj);

extern "C" void func_0044C078(Obj *self, void *ctx) {
    if (self->hidden == 0) {
        func_0043C8D8(ctx, self);
        if (self->dirty)
            func_0043C8E8(ctx, self);
    }
}

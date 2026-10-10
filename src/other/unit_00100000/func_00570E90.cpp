struct Obj {
    char pad0[0x7C];
    void *a;
    void *b;
};

extern "C" int func_00488A88(Obj *self, void *a, void *b, void *arg, int *count, void *extra);

extern "C" int func_00570E90(Obj *self, void *arg, int *count, void *extra) {
    int r = func_00488A88(self, self->a, self->b, arg, count, extra);
    if (r == 0 && *count == 0)
        return -2;
    return r;
}

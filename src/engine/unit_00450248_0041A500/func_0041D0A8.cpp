struct Inner {
    char pad[0x18];
    void *target;
};

struct Ctrl {
    Inner *inner;
    char pad[0x2C];
    int value;
};

extern "C" void *func_0041AB50(Ctrl *c);
extern "C" void func_00420730(void *target, int value, void *ctx);

extern "C" void func_0041D0A8(Ctrl *c, int value)
{
    if (c->inner) {
        void *target = c->inner->target;
        void *ctx = func_0041AB50(c);
        if (target && ctx) {
            c->value = value;
            func_00420730(target, value, ctx);
        }
    }
}

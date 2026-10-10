struct KeyEvent {
    char pad0[0x20];
    unsigned int key;
};

struct mWidget;
struct mKeytopBox;

extern "C" int func_00250D10(mKeytopBox *self, void *ctx);
extern "C" mWidget *func_00210118(mKeytopBox *self);
extern "C" void func_001E2D70(void *ctx, mWidget *root);

extern "C" int mKeytopBox__onKeyPress(mKeytopBox *self, void *ctx, KeyEvent *e) {
    switch (e->key) {
    case 0xFF0D:
    case 0xFF8D:
        return func_00250D10(self, ctx);
    case 0xFF1B:
        func_001E2D70(ctx, func_00210118(self));
        return 2;
    }
    return 0;
}

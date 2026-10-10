extern void *D_00586EF4;
extern "C" void func_00415E70(void *self, int flag);
extern "C" void func_0045FE50(void *ctx, void *item, int a, int b, int c);
extern "C" void func_00415FC8(void *self);

extern "C" void func_00415CC0(void *self, void *item) {
    func_00415E70(self, 0);
    func_0045FE50(D_00586EF4, item, 0, 0, 0);
    func_00415FC8(self);
}

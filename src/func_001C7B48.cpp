/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0046F0F8(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00478C98(int);
extern "C" void mRenderContextPS2__virtual_55(void *self, int kind) {
    switch (kind) {
    case 0:
        func_0046F0F8(6);
        return func_004702D8(0x44, 1.0f);
    case 1:
        func_0046F0F8(6);
        return func_004702D8(0x48, 1.0f);
    case 2:
        return func_00478C98(6);
    }
}

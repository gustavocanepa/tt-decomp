struct Sys {
    int handle;
    char pad4[0x3F8 - 4];
    int ready;
};

extern "C" Sys D_00779680;
extern "C" char D_00779E80[];
extern "C" void func_004F4348(int handle);
extern "C" void func_004F45D8(Sys *s, int kind, int a, void *buf, int size);

extern "C" void func_004C95C8(void) {
    Sys *s = &D_00779680;
    func_004F4348(s->handle);
    s->ready = 1;
    func_004F45D8(s, 3, 0, D_00779E80, 0x80);
}

extern char D_00586EF4[];
extern char D_00586EF8[];

extern "C" void *exception__structor_0(int size);
extern "C" void func_0045E318(void *self);

extern "C" void func_0045DED8(void) {
    void **slot;
    void *obj;
    slot = (void **)D_00586EF4;
    if (*slot == 0) {
        obj = exception__structor_0(0xC0);
        func_0045E318(obj);
        *slot = obj;
    }
    slot = (void **)D_00586EF8;
    if (*slot == 0) {
        obj = exception__structor_0(0xC0);
        func_0045E318(obj);
        *slot = obj;
    }
}

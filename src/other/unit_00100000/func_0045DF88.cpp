extern void *D_00586EF4;
extern void *D_00586EF8;
extern "C" void *func_0045E768(void *mgr, void *obj);
extern "C" void func_0045E8D8(void *mgr, void *item);

extern "C" void func_0045DF88(void *obj) {
    if (D_00586EF4 && obj) {
        void *item = func_0045E768(D_00586EF4, obj);
        if (D_00586EF8 && item)
            func_0045E8D8(D_00586EF8, item);
    }
}

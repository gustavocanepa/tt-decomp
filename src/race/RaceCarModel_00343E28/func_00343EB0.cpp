/* compiler: ee-gcc2.96-no-strict-aliasing */
struct CB { void (*fn)(void *, int); void *arg; };
extern "C" void func_00343F40(void *, void *);
extern "C" void *exception__structor_0(int);
extern "C" char *func_004F7B74(char *, const char *);
extern "C" void func_00343E68(void *, int);
extern "C" void func_0042F110(void *, CB *);
extern "C" void func_00343EB0(char *o, const char *name, int mode) {
    CB cb;
    if (*(int *)(o + 0x354C) == 0) {
        if (mode == 2) {
            func_00343F40(o, 0);
            return;
        }
        char *p = (char *)exception__structor_0(0x104);
        *(void **)(p + 0x100) = o;
        func_004F7B74(p, name);
        cb.fn = func_00343E68;
        cb.arg = p;
        func_0042F110(p, &cb);
    }
}

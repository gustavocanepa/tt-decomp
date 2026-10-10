typedef void (*Handler)(void);
typedef void (*NoReturnHandler)(void) __attribute__((noreturn));

extern Handler D_005A4794;

/* terminate(): calls the installed handler, which never returns. */
extern "C" void func_0050E1E8(void) __attribute__((noreturn));
extern "C" void func_0050E1E8(void) {
    ((NoReturnHandler)D_005A4794)();
}

/* A wrapper that never returns either (glued after it in the inventory). */
extern "C" void func_005C1680(void) __attribute__((noreturn));
extern "C" void func_005C1680(void) {
    func_0050E1E8();
}

/* set_terminate(): installs a new handler and returns the old one. */
extern "C" Handler func_005C1690(Handler h) {
    Handler *p = &D_005A4794;
    Handler old = *p;
    *p = h;
    return old;
}

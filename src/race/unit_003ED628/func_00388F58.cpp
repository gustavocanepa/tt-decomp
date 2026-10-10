extern "C" void *func_00388CE0(void *holder);
extern "C" void func_00388C88(void *holder, void *obj);
extern "C" void *func_0042FAA8(void *desc, int flags);
extern "C" char D_00584778[];
extern "C" char D_00584758[];

extern "C" void *func_00388F58(void)
{
    void *p = func_00388CE0(D_00584778);
    if (!p) {
        func_00388C88(D_00584778, func_0042FAA8(D_00584758, 0));
        p = func_00388CE0(D_00584778);
    }
    return p;
}

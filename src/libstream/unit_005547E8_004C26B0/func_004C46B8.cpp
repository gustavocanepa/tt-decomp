extern int D_0059C0D8;
extern char D_0059D4A8[];

extern "C" void func_004C9368(void);
extern "C" void func_004C7048(void *p, float rate);
extern "C" void func_004C7DE0(void);
extern "C" void func_004C6D00(void);
extern "C" void func_004C4EB0(void);
extern "C" void func_004C4070(void);
extern "C" void func_004C9918(void);

extern "C" void func_004C46B8(void) {
    int *initialized = &D_0059C0D8;
    if (*initialized)
        return;
    *initialized = 1;
    func_004C9368();
    func_004C7048(D_0059D4A8, 60.0f);
    func_004C7DE0();
    func_004C6D00();
    func_004C4EB0();
    func_004C4070();
    func_004C9918();
}

struct Req {
    int f0;
    int busy;
    int f8;
};

extern "C" Req D_00775300[];
extern "C" void func_004BA510(void *arg);
extern "C" void func_004B9F78(int ch, int a, int b, int d, int c, void (*cb)(void *), void *arg);

extern "C" void func_004BA628(int ch, int a, int b, int c, int d) {
    Req *r = &D_00775300[ch];
    r->busy = 1;
    func_004B9F78(ch, a, b, d, c, func_004BA510, r);
}

struct Desc {
    void (*entry)(void *);
    void *arg;
};

extern "C" int D_0059832C;
extern "C" char D_00773E70[];
extern "C" void func_004B54E0(void *arg);
extern "C" int func_004A58E0(int a, int b);
extern "C" int func_004A53A0(int h);
extern "C" int func_004AF398(Desc *d, int prio);
extern "C" void func_004A5618(int h);

extern "C" void func_004B5500(void)
{
    if (D_0059832C == 0) {
        Desc d;
        d.entry = func_004B54E0;
        d.arg = D_00773E70;
        D_0059832C = func_004AF398(&d, func_004A53A0(func_004A58E0(3, 0)));
        func_004A5618(D_0059832C);
    }
}

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_004A59F0(void);
extern "C" int func_004DB3F8(void *p);
extern "C" char D_005A07B0[];

extern "C" int func_004CB560(void *p)
{
    int r;
    func_004A4D68(D_005A07B0);
    while ((r = func_004DB3F8(p)) < 0)
        func_004A59F0();
    func_004A4DD8(D_005A07B0);
    return r;
}

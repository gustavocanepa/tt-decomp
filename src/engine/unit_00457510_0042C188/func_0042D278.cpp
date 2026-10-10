extern int D_00585F24;
extern char D_0076A088[];
extern char D_0076A090[];

extern "C" void func_004A4930(void *mutex);
extern "C" void func_004A4970(void *mutex);
extern "C" int func_00535818(void *obj);
extern "C" int func_004B2AC8(void);

extern "C" int func_0042D278(void)
{
    if (D_00585F24 == 0)
        return func_004B2AC8();
    void *mutex = D_0076A088;
    func_004A4930(mutex);
    int r = func_00535818(D_0076A090);
    func_004A4970(mutex);
    return r;
}

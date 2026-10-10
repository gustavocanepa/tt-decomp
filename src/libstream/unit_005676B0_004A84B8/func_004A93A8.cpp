extern "C" void func_004A59F0(void);
extern "C" int func_005037C8(int id);
extern "C" int func_00503778(void);

extern "C" void func_004A93A8(void *self, int id)
{
    while (!func_005037C8(id))
        func_004A59F0();
    while (!func_00503778())
        func_004A59F0();
}

extern "C" void *func_003E4710(void *self, int i);
extern "C" void func_003E1B60(void *item);

extern "C" void func_003E57C8(void *self)
{
    for (int i = 0; i < 20; i++)
        func_003E1B60(func_003E4710(self, i));
}

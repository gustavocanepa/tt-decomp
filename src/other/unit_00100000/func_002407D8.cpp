extern "C" void func_00243970(void *self, void *arg, int flag);
extern "C" void func_002404E0(void *self, void *arg);

extern "C" void func_002407D8(void *self, void *arg, int on)
{
    func_00243970(self, arg, 0);
    if (on)
        func_002404E0(self, arg);
}

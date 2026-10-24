extern "C" void func_0032FD20(void *self, int i, int arg);
extern "C" void func_0032FD80(void *self, int arg);

extern "C" void func_0032FCA8(void *self, int arg, int count) {
    for (int i = 0; i < 11; i++)
        func_0032FD20(self, i, arg);
    if (count)
        func_0032FD80(self, arg);
}

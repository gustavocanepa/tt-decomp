extern "C" int func_003EEBE8(int t, int name);
extern "C" void func_003EF9D8(void *self, int idx, float a, int arg, float b);

extern "C" void func_003EFA70(void *self, int name, float a, int arg, float b) {
    int p = *(int *)((char *)self + 4);
    if (p != 0) {
        func_003EF9D8(self, func_003EEBE8(p, name), a, arg, b);
    }
}

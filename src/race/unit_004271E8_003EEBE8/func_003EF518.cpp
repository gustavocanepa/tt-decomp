extern "C" int func_003EEBE8(int);
extern "C" void func_003EF458(void *self, int a, float b, float c, float d, float e, int f, float g);

extern "C" void func_003EF518(void *self, int unused, float b, float c, float d, float e, int f, float g) {
    int p = *(int *)((char *)self + 4);
    if (p != 0) {
        func_003EF458(self, func_003EEBE8(p), b, c, d, e, f, g);
    }
}

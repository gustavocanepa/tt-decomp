extern "C" void *func_00448190(void *self, int key);
extern "C" void *func_00447FB0(void *self, int key);
extern "C" void func_0043D3E0(void *item, int value);

extern "C" int func_0044B188(void *self, int key, int value, int create) {
    if (create) {
        func_0043D3E0(func_00448190(self, key), value);
        return 1;
    }
    void *p = func_00447FB0(self, key);
    if (!p)
        return 0;
    func_0043D3E0(p, value);
    return 1;
}

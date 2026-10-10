typedef int s32;

extern "C" void *func_0040FDA0(void *);
extern "C" void *func_0040FB40(void *);
extern "C" s32 func_0040FFE8(void *, void *);

extern "C" s32 func_00410058(void *key, void *out) {
    void *p = func_0040FDA0(key);
    if (p == 0)
        return 0;
    return func_0040FFE8(func_0040FB40(p), out);
}

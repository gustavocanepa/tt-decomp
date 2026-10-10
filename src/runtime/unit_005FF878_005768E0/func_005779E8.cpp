extern "C" void func_004A4D68(void *mutex);
extern "C" void func_004A4DD8(void *mutex);

struct Lock {
    void *m;
    Lock(void *mutex) : m(mutex) { func_004A4D68(m); }
    ~Lock() { func_004A4DD8(m); }
};

struct Stream {
    char pad0[0x1C];
    char mutex[4];
};

extern "C" int func_004F4998(Stream *s, void *a, int b);

extern "C" int func_005779E8(Stream *s, void *a, int b)
{
    Lock lock(s->mutex);
    return func_004F4998(s, a, b);
}

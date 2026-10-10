/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mutex { int w[2]; };

extern "C" void func_004A4D68(Mutex *m);
extern "C" void func_004A4DD8(Mutex *m);

struct ScopedLock {
    Mutex *m;
    ScopedLock(Mutex *mutex) : m(mutex) { func_004A4D68(m); }
    ~ScopedLock() { func_004A4DD8(m); }
};

struct Range {
    int first;
    int second;
};

struct Obj {
    char pad[0x1C];
    Mutex mutex;
};

extern "C" void func_004F48A0(Obj *o, int first, int flag, int second);

extern "C" void func_00577758(Obj *o, const Range *r) {
    int first = r->first;
    int second = r->second;
    ScopedLock lock(&o->mutex);
    func_004F48A0(o, first, 1, second);
}

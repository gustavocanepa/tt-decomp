extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" void func_004AEB30(void *p);

struct LockGuard {
    void *lock;
    LockGuard(void *l) : lock(l) { func_004A4930(l); }
    ~LockGuard() { func_004A4970(lock); }
};

struct State {
    char pad0[0x39];
    unsigned char dirty;
};

extern "C" char D_00773E68[];
extern "C" State D_00773E70;

extern "C" void func_004B5878(void) {
    State *s = &D_00773E70;
    {
        LockGuard guard(D_00773E68);
        s->dirty = 1;
    }
    func_004AEB30(s);
}

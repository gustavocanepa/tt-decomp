extern "C" void func_004A4D68(void *mutex); /* lock */
extern "C" void func_004A4DD8(void *mutex); /* unlock */

struct ScopedLock {
    void *mutex;
    ScopedLock(void *m) : mutex(m) { func_004A4D68(mutex); }
    ~ScopedLock() { func_004A4DD8(mutex); }
};

struct Obj {
    char pad0[0x1C];
    char mutex[4];
};

extern "C" void func_004F4968(Obj *self, void *item);

extern "C" void func_00577918(Obj *self, void *item) {
    ScopedLock lock(self->mutex);
    if (item)
        func_004F4968(self, item);
}

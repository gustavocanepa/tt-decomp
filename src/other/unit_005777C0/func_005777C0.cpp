extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004F48C0(void *);

/* Scoped lock: locks in the constructor, unlocks in the destructor. */
struct Lock {
    void *m;
    Lock(void *mutex) : m(mutex) { func_004A4D68(m); }
    ~Lock() { func_004A4DD8(m); }
};

struct Obj {
    char pad[0x1C];
    char mutex[4];
};

extern "C" void func_005777C0(Obj *self) {
    Lock lock(self->mutex);
    func_004F48C0(self);
}

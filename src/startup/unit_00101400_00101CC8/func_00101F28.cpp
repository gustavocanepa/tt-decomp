/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mutex {
    void lock() __asm__("func_004A4D68");
    void unlock() __asm__("func_004A4DD8");
};

struct Owner;

struct Listener {
    virtual void v0();
    virtual void notify(Owner *o);
};

struct Owner {
    char pad0[0x6C];
    Mutex mutex;
    char pad6D[0x9C - 0x6D];
    Listener *listener;
    char padA0[0xAC - 0xA0];
    int state;
    void func_00101F28() __asm__("func_00101F28");
};

void Owner::func_00101F28() {
    mutex.lock();
    int *p = &state;
    bool b = *p != 3;
    if (b) {
        *p = 2;
        listener->notify(this);
    }
    mutex.unlock();
}

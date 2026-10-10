extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);

struct Lock {
    int w[4];
};

struct LockGuard {
    Lock *lock;
    LockGuard(Lock *l) : lock(l) { func_004A4D68(l); }
    ~LockGuard() { func_004A4DD8(lock); }
};

struct List {
    int head;
    int count;
    int tail;
    char pad[0x1C - 0xC];
    Lock lock;
    void clear() __asm__("func_00577800");
};

void List::clear() {
    LockGuard guard(&lock);
    head = 0;
    count = 0;
    tail = 0;
}

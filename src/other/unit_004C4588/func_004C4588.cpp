extern "C" char D_005A0B88[];
extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" void func_004C4218(void *self);

extern "C" void func_004C4588(void *self) {
    void *lock = D_005A0B88;
    func_004A4930(lock);
    func_004C4218(self);
    func_004A4970(lock);
}

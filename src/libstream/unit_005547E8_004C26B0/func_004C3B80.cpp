extern "C" char D_005A0B88[];
extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);

extern "C" void func_004C3B80(void *self) {
    void *lock = D_005A0B88;
    func_004A4930(lock);
    ((int *)self)[0x5C / 4] = 2;
    func_004A4970(lock);
}

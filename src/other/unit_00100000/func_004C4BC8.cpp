extern char D_005A0B88[]; /* mutex */
extern "C" void func_004A4930(void *mutex);
extern "C" void func_004A4970(void *mutex);
extern "C" void func_004C4CB0(void *self, void *arg);
extern "C" void func_004C47F0(void *self);

extern "C" void func_004C4BC8(void *self, void *arg) {
    void *mutex = D_005A0B88;
    func_004A4930(mutex);
    func_004C4CB0(self, arg);
    func_004C47F0(self);
    func_004A4970(mutex);
}

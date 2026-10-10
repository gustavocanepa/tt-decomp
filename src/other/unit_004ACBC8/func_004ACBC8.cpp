struct S { char pad[0xC]; char lock[1]; };

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);
extern "C" void func_004AC838(S *arg0, void *arg1);

extern "C" void func_004ACBC8(S *arg0, void *arg1) {
    void *lock = &arg0->lock;
    func_004A4D68(lock);
    func_004AC838(arg0, arg1);
    func_004A4DD8(lock);
}

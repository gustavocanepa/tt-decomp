struct Obj;

extern "C" char *func_004FA5D0(Obj *arg0);

extern "C" void func_004FB4C0(Obj *arg0) {
    func_004FA5D0(arg0);
    __asm__ volatile("sync");
}

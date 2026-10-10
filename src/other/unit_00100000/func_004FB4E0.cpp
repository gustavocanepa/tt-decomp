struct Obj;

extern "C" char *func_004FA5E0(Obj *arg0);

extern "C" void func_004FB4E0(Obj *arg0) {
    func_004FA5E0(arg0);
    __asm__ volatile("sync");
}

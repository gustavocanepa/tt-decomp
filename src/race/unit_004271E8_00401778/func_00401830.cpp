extern "C" long func_004017F8(char *self);
extern "C" void func_003FBF98(char *p, long v);

extern "C" void func_00401830(char *self, long x) {
    char *p = self + 0x260;
    func_003FBF98(p, x + func_004017F8(self));
}

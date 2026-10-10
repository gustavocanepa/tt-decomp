extern "C" void func_004AA990(void *, void *);
extern "C" void func_004AAA88(void *, void *);

extern "C" void func_004AABA8(char *self) {
    char *a = self + 0x58;
    func_004AA990(self, a);
    func_004AAA88(a, self + 0x68);
}

struct B80 { char x[80]; };
struct VE { short d, p; void (*fn)(void *, void *); };
extern "C" int func_00400D08(void *a, int n);

extern "C" void func_004001F8(char *self, char *dst) {
    *(B80 *)dst = *(B80 *)(self + 4);
    func_00400D08(dst, 0x50);
    VE *v = (VE *)(*(char **)self + 0x20);
    v->fn(self + v->d, dst);
}

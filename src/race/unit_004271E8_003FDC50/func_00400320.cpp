struct B80 { char x[80]; };
struct VE { short d, p; void (*fn)(void *, void *); };
extern "C" int func_00400D38(void *a, int n);

extern "C" void func_00400320(char *self, char *src) {
    *(B80 *)(self + 4) = *(B80 *)src;
    func_00400D38(src, 0x50);
    VE *v = (VE *)(*(char **)self + 0x20);
    v->fn(self + v->d, src);
}

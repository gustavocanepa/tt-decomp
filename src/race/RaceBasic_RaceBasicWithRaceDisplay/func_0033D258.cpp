/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d; short i; void (*fn)(void *, int); };
extern "C" void func_0033A048(void);
extern "C" void func_0033D258(char *self) {
    func_0033A048();
    char *o = *(char **)(self + 0xE4E0);
    if (o) {
        VE *e = (VE *)(*(char **)o + 0x40);
        e->fn(o + e->d, *(int *)(self + 0xD8C));
    }
}

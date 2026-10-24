/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d; short i; void (*fn)(void *); };
extern "C" void func_002CEB78(char *);
extern "C" void func_00379E20(void *);
extern "C" void RaceBasic__cleanup(char *self) {
    char *o = *(char **)(self + 0xE4E0);
    if (o) {
        VE *e = (VE *)(*(char **)o + 8);
        e->fn(o + e->d);
    }
    o = *(char **)(self + 0xE4DC);
    if (o) {
        VE *e = (VE *)(*(char **)(o + 0x18) + 0x18);
        e->fn(o + e->d);
    }
    o = *(char **)(self + 0xE4C0);
    if (o) {
        VE *e = (VE *)(*(char **)(o + 8) + 0x18);
        e->fn(o + e->d);
    }
    o = *(char **)(self + 0xE4C4);
    if (o) {
        VE *e = (VE *)(*(char **)(o + 8) + 0x18);
        e->fn(o + e->d);
    }
    void *p = *(void **)(self + 0xE4CC);
    if (p) func_00379E20(p);
    func_002CEB78(self);
}

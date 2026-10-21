/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00769D78[];
extern "C" unsigned long func_0044C948(const char *);
extern "C" int func_0044C720(void *, unsigned long);
extern "C" long func_0044C920(void *, int);
struct Instrument {
    void play(unsigned, float, int) throw() __asm__("func_0042B3F8");
};
extern "C" void func_0042B678(const char *name, unsigned select, float volume, int mode) {
    int i = func_0044C720(D_00769D78, func_0044C948(name));
    if (i >= 0) {
        Instrument *p = (Instrument *)(int)func_0044C920(D_00769D78, i);
        p->play(select, volume, mode);
    }
}

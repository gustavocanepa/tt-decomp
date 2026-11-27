/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_003695A8(void *, int);
extern "C" void func_00369778(void *);
extern "C" void func_00376390(void *, int, int);
extern "C" void func_0037C048(char *, char *);
static inline void setFlag(char *p, int flag) { *(int *)(p + 0x1168) = flag; }
static inline void loadGhost(char *race, char *src, int flag) {
    func_00376390(race, 2, 0);
    char *p = *(char **)(*(char **)(*(char **)(race + 0x60) + 8) + 4);
    func_003695A8(p, 1);
    func_0037C048(p, src + 0x960);
    setFlag(p, flag);
    func_00369778(p);
}

extern "C" void func_0033BB18(char *self,char *src) { loadGhost(*(char **)(self+0x6c),src,1); }

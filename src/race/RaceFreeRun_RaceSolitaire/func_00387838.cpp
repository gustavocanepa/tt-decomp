/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, int); };
extern "C" void func_0033A0C8(void *, int);
extern "C" void *func_00386940(void *) throw();
extern "C" char *func_002E8A48(void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(void *, void *, int, void *, void *, void *);
extern char func_00556128[];
extern char func_00554648[];
extern "C" void func_00387838(char *self, int frames) {
    char *target = 0;
    func_0033A0C8(self, frames);
    char *p = *(char **)(self + 0xE4E0);
    *(float *)(self + 0xD004) = -0.5f;
    if (p) {
        char *v = *(char **)p;
        target = (char *)GT4MC__FileGT4GameData__loadInstance(*(void **)(v + 4), func_00556128, 0, p + *(short *)v, func_00554648, p);
    }
    char *record = func_002E8A48((char *)func_00386940(self) + 0xd4);
    if (target && record) {
        VEntry *e = (VEntry *)(*(char **)target + 0x198);
        e->fn(target + e->delta, *(int *)(record + 0x10));
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void *fn; };
struct Obj { int x; Entry *vt; };
extern char func_00546A40[], func_0054D6E8[];
extern "C" void func_00278E18(void *, void *);
extern "C" void *func_001F8708(void *, void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(void *, void *, int, void *, void *, void *);
extern "C" void func_00288B88(char *self, Obj *src) {
    func_00278E18(self, src);
    char *p = 0;
    if (src) {
        Entry *e = src->vt;
        p = (char *)GT4MC__FileGT4GameData__loadInstance(e->fn, func_00546A40, 0, (char *)src + e->delta, func_0054D6E8, src);
    }
    if (p) func_001F8708(self + 0xE4, p + 0xE4);
}

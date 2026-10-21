/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void *fn; };
struct Obj { int x; Entry *vt; };
extern char func_005290F0[], func_0054D6E8[];
extern "C" void func_00245598(void *, void *);
extern "C" void *func_001D3190(void *, void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(void *, void *, int, void *, void *, void *);
extern "C" void func_001D1CD8(char *self, Obj *src) {
    func_00245598(self, src);
    char *p = 0;
    if (src) {
        Entry *e = src->vt;
        p = (char *)GT4MC__FileGT4GameData__loadInstance(e->fn, func_005290F0, 0, (char *)src + e->delta, func_0054D6E8, src);
    }
    if (p) func_001D3190(self + 0x178, p + 0x178);
}

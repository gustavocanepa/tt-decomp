/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char pad[0x10]; float value; char rest[0x1c]; };
struct Obj { char pad[0x30]; Entry *entries; };
extern "C" int func_0037C740() throw() __attribute__((const));
extern "C" int func_0037C738(Obj *, int) throw();
extern "C" int func_0037C748(Obj *self, int arg, float value) {
    int start = func_0037C740();
    if (value < self->entries[start].value) return -1;
    int hi = func_0037C738(self, arg);
    int lo = 0;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (value < self->entries[mid + start].value) hi = mid;
        else lo = mid + 1;
    }
    return lo - 1;
}

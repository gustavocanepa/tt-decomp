/* compiler: ee-gcc2.96-nogcse */
struct Range { int index; int low; int high; };
struct Obj { char pad[0xE0]; Range r; char padC8[0x28]; signed char *disabled; };
extern "C" void func_0027AAB0(Obj *, int, int) throw();
extern "C" void func_004AC580(Range *, int);
extern "C" int func_004AC650(Range *, int);
extern "C" int func_0027AB48(Obj *self, int step) {
    Range *r = &self->r;
    int old = r->index;
    int result = func_004AC650(r, step);
    signed char *disabled = self->disabled;
    if (disabled) {
        int index = r->index;
        while (disabled[index]) {
            ++index;
            if (index >= r->high) {
                func_004AC580(r, old);
                return 0;
            }
        }
        func_004AC580(r, index);
    }
    func_0027AAB0(self, old, r->index);
    return result;
}

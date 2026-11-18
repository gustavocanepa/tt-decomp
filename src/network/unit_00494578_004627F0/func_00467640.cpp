/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { void *data; unsigned int desc; unsigned short x, y; };
struct Obj { char pad0[0x16]; unsigned short count; int pad18; Entry *entries; };
extern "C" int func_0046E9C8(int);
extern "C" int func_0046E9F8(int);
extern "C" int func_0046EA28(int);
extern "C" int func_0046EC00(int, void *, int);
extern "C" void func_0046FB98();
extern "C" int func_004729C0(void *, void *, int, int, unsigned short, unsigned short);
extern "C" void func_004FAAA0(int);
extern "C" void func_00467640(Obj *self) {
    char buf[0x60];
    func_0046FB98();
    for (int i = 0; i < self->count; i++) {
        Entry *e = &self->entries[i];
        int n = func_004729C0(buf, &e->desc, 0, 0, e->x, e->y);
        if (n != 0) {
            func_004FAAA0(0);
            func_0046E9C8(2);
            func_0046EC00(2, buf, 6);
            func_0046EC00(2, e->data, n);
            func_0046EA28(2);
            func_0046E9F8(2);
        }
    }
}

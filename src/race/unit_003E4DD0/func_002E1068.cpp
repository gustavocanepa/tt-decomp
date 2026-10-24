/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char *items;
    int count;
};
extern "C" void func_004242C0(void *, void *);
extern "C" void GT4Model__BinStreamReader__read8u(void *);
extern "C" int func_00423DE0(void *);
extern "C" int func_00423E80(void *);
extern "C" void func_004243E0(void *, void *);
extern "C" void func_002E0AB8(Obj *, void *) throw();
extern "C" void func_002E0B18(void *, void *) throw();
extern "C" void func_002E1240(void *, void *);

extern "C" void func_002E1068(Obj *self, void *stream) {
    int buf[4];
    int i = 0;
    func_004242C0(buf, stream);
    GT4Model__BinStreamReader__read8u(stream);
    func_00423DE0(stream);
    if (self->count > 0) {
        int off = 0;
        do {
            char *it = self->items + off;
            off += 0x60;
            func_002E0AB8(self, it);
            if (func_00423E80(stream)) {
                if (func_00423E80(stream)) func_002E1240(it, stream);
            } else {
                func_002E0B18(self, it);
            }
            i++;
        } while (i < self->count);
    }
    func_004243E0(buf, stream);
}

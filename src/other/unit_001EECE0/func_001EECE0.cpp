typedef int s32;

struct Handle {
    s32 p;
};

struct Obj {
    char pad[0x14];
    Handle h;
};

extern "C" void func_002661E8(s32);
extern "C" void func_00266330(s32, s32);

extern "C" void func_001EECE0(Obj *self, s32 arg1, s32 arg2) {
    Handle *h = &self->h;
    func_002661E8(h->p);
    func_00266330(h->p, arg2);
}

typedef int s32;

struct Obj {
    char pad[0x80];
    s32 state;
    bool done() { return state == 3; }
};

extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004A4E08(void *);

extern "C" void func_0047ECC0(Obj *self) {
    func_004A4D68(self);
    if (!self->done())
        func_004A4E08(self);
    func_004A4DD8(self);
}

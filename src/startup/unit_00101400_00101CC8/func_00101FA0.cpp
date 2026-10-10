struct Obj {
    char pad0[0x6C];
    char mutex[0x40];
    int count;
};

extern "C" void func_004A4D68(void *mutex);
extern "C" void func_004A4DD8(void *mutex);
extern "C" void func_00109618(Obj *self);

extern "C" void func_00101FA0(Obj *self) {
    func_004A4D68(self->mutex);
    int n = self->count;
    if (n < 3) {
        self->count = ++n;
        if (n == 3)
            func_00109618(self);
    }
    func_004A4DD8(self->mutex);
}

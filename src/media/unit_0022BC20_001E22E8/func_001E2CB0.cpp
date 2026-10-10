typedef int s32;

struct Obj {
    char pad0[0x44];
    s32 flag;
    char lock[4];
};

extern "C" void func_004A4D68(void *lock);
extern "C" void func_004A4DD8(void *lock);

extern "C" void func_001E2CB0(Obj *self) {
    func_004A4D68(self->lock);
    self->flag = 1;
    func_004A4DD8(self->lock);
}

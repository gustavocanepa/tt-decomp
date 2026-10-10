typedef int s32;

struct Obj {
    s32 lock;
    s32 unk4;
    s32 active;
    s32 dirty;
};

extern "C" void func_00178360(Obj *);
extern "C" void func_004A4E08(s32);
extern "C" void func_00178380(Obj *);

extern "C" void func_00178310(Obj *self) {
    if (self->active != 0) {
        func_00178360(self);
        self->dirty = 1;
        func_004A4E08(self->lock);
        func_00178380(self);
    }
}

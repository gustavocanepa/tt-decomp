typedef int s32;

struct Obj {
    s32 lock;
    s32 unk4;
    s32 active;
    s32 dirty;
};

extern "C" void func_003CBDB8(Obj *);
extern "C" void func_003CBE18(Obj *);
extern "C" void func_003CBE90(Obj *);
extern "C" void func_003CBF30(Obj *);

extern "C" void func_003CC050(Obj *self) {
    if (self->unk4 != 0) {
        func_003CBDB8(self);
        func_003CBE18(self);
        func_003CBE90(self);
        func_003CBF30(self);
    }
}

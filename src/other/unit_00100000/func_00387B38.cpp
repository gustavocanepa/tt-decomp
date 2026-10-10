typedef int s32;

struct Tmp {
    s32 w[4];
};

struct Obj {
    char pad[0xD0];
    s32 unkD0;
};

extern "C" void func_003EEC90(Tmp *);
extern "C" void func_003EECA0(Tmp *, s32, s32);
extern "C" s32 func_003F1700(Tmp *);

extern "C" s32 func_00387B38(Obj *self) {
    if (self->unkD0 == 0)
        return 0;
    Tmp t;
    func_003EEC90(&t);
    func_003EECA0(&t, 0, self->unkD0);
    return func_003F1700(&t);
}

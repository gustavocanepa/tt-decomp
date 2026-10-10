typedef int s32;

struct Obj {
    char pad[0xE4D8];
    s32 active;
};

extern "C" void func_0033DBC8(Obj *);
extern "C" void func_0036E340(Obj *, s32);

extern "C" void RaceFreeRun__virtual_149(Obj *self) {
    func_0033DBC8(self);
    if (self->active != 0)
        func_0036E340(self, 1);
}

typedef int s32;

struct Obj {
    s32 unk0;
    s32 state;
    char sub[0x5C];
    s32 unk64;
    s32 unk68;
};

extern "C" void func_002E88B0(Obj *self, s32 a);
extern "C" void func_002E7BE0(void *sub);

extern "C" void AutomobileControlRecord__Manager__reset(Obj *self) {
    if (self->state == 1) {
        self->unk64 = 0;
        self->unk68 = 0;
        func_002E88B0(self, 0);
    }
    func_002E7BE0(self->sub);
}

typedef int s32;

struct Obj {
    char pad0[0x13A0C];
    char unk123CC[4];
};

extern "C" void *func_0033BC80(Obj *self, s32 id);

extern "C" void *RaceSinglePlayer__getInput(Obj *self, s32 id) {
    if (id == 0x100) {
        return self->unk123CC;
    }
    return func_0033BC80(self, id);
}

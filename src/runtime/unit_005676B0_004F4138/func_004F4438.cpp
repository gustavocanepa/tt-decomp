typedef int s32;
struct Obj00577FC8 {
    char pad0[0x24];
    s32 unk24;
};
extern "C" void func_004A59F0(void);
extern "C" s32 func_004FE350(Obj00577FC8 *self, s32 arg1, s32 arg2);

extern "C" void func_004F4438(Obj00577FC8 *self, s32 arg1, s32 arg2) {
    self->unk24 = 0;
    for (;;) {
        while (func_004FE350(self, arg1, arg2) < 0) {
            func_004A59F0();
        }
        if (self->unk24 != 0) {
            return;
        }
        func_004A59F0();
        if (self->unk24 != 0) {
            return;
        }
    }
}

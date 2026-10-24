#include "types.h"

struct Obj {
    char pad0[0x694];
    s32 unk694;
    char pad698[0x6E0 - 0x698];
    s32 thread;
};

struct ThreadDesc {
    void (*entry)(void);
    Obj *arg;
    s32 pad[2];
};

extern "C" void func_00198920(void);
extern "C" s32 func_004AF398(ThreadDesc *desc, s32 arg1);
extern "C" void func_00198940(Obj *self, s32 value);
extern "C" void func_004A5618(s32 thread);

extern "C" void func_00198980(Obj *self) {
    ThreadDesc desc;
    desc.entry = func_00198920;
    desc.arg = self;
    self->thread = func_004AF398(&desc, 0);
    self->unk694 = 0;
    func_00198940(self, 5);
    func_004A5618(self->thread);
}

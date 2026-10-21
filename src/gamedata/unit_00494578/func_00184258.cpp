#include "types.h"

extern "C" void func_0020B408(void *);
extern "C" void func_001A5650(void *, s32);
extern "C" s32 func_001802A0(s32);
extern "C" s32 func_001802B0(s32);
extern "C" void func_002CD060(s32);

struct PhotoRenderFace_0019B668 {
    u8 pad0[0xA0];
    void *handle;
};

extern "C" void func_00184258(PhotoRenderFace_0019B668 *self, s32 arg1) {
    void *owner = self;
    func_0020B408(owner);
    void **handle_slot = (void **)((u8 *)owner + 0xB4);
    if (*handle_slot != 0) {
        func_001A5650(*handle_slot, 3);
    }
    *handle_slot = 0;
    s32 first = func_001802A0(arg1);
    if (first != 0 && func_001802B0(arg1) != 0) {
        func_002CD060(first);
    }
}

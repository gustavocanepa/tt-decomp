#include "types.h"

struct hObjectNative {
    u32 unk0;
    u32 vtable;
    u32 unk8;
    u32 unkC;
    hObjectNative() __asm__("func_002A7618");
};

struct CopyBlock_0017D490 {
    u64 words[0x191];
};

struct mMemoryCardPlayListNative : hObjectNative {
    void *data;
    s32 initialized;
    u32 unk18;
    mMemoryCardPlayListNative(const CopyBlock_0017D490 *source) __asm__("func_00159920");
};

extern "C" void *exception__structor_0(s32);
extern "C" u32 D_005A7C10;

mMemoryCardPlayListNative::mMemoryCardPlayListNative(const CopyBlock_0017D490 *source)
    : hObjectNative() {
    vtable = (u32)&D_005A7C10;
    void *allocation;
    if (source != 0) {
        allocation = exception__structor_0(0xC88);
        *(CopyBlock_0017D490 *)allocation = *source;
    } else {
        allocation = exception__structor_0(0xC88);
        *(s32 *)((u8 *)allocation + 0xC80) = 0;
    }
    data = allocation;
    initialized = 1;
}

#include "types.h"

struct VEntryFloat {
    short delta;
    short index;
    void (*fn)(void *, void *, float);
};
struct VEntryVoid { short delta; short index; void (*fn)(void *, void *); };

extern "C" void func_00478C98(s32);
extern "C" void func_0046F0F8(s32);
extern void *D_005798BC;
struct Target { char pad[0x34]; float width; float height; };
extern Target *D_00586EF4;
extern char D_00579534[];

extern "C" void func_0011FAF0(void) {
    func_00478C98(0x12);
    char *base = D_00579534;
    s32 index = *(s32 *)(base + 0x78);
    s32 entryOffset = index << 4;
    entryOffset -= index;
    entryOffset <<= 2;
    char *entryData = base + entryOffset;
    void *global = &D_005798BC;
    void *obj = *(void **)global;
    VEntryFloat *entry = (VEntryFloat *)((char *)*(void **)((char *)obj + 0x64) + 0x368);
    entry->fn((char *)obj + entry->delta, entryData, 0.0f);
    obj = *(void **)global;
    VEntryVoid *entry2 = (VEntryVoid *)((char *)*(void **)((char *)obj + 0x64) + 0x378);
    entry2->fn((char *)obj + entry2->delta, entryData);
    obj = *(void **)global;
    VEntryVoid *entry3 = (VEntryVoid *)((char *)*(void **)((char *)obj + 0x64) + 0x380);
    entry3->fn((char *)obj + entry3->delta, entryData);
    D_00586EF4->width = 640.0f;
    D_00586EF4->height = 480.0f;
    func_0046F0F8(0x12);
}

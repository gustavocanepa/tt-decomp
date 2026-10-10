typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj003EAC18 {
    char pad[0x64];
    char *unk64;
};

extern "C" void func_00372C20(s32 arg0);

extern "C" void func_00386C90(struct Obj003EAC18 *arg0)
{
    VEntry *e = (VEntry *)(arg0->unk64 + 0x90);

    func_00372C20(e->fn((char *)arg0 + e->delta));
}

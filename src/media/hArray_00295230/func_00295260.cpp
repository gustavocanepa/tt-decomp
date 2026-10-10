/* Virtual call through a handle: (*h)->slot 17 (vtable entry at +0x88) with the argument passed on. */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 *(*fn)(void *, s32);
};

struct Obj {
    s32 count;
    VEntry *vtbl;
};

extern "C" s32 *func_00295260(Obj **h, s32 arg)
{
    Obj *obj = *h;
    VEntry *entry = obj->vtbl + 17;
    return entry->fn((char *)obj + entry->delta, arg);
}

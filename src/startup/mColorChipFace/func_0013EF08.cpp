#include "types.h"

struct Entry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[4];
    Entry *vtable;
};

struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; };

extern char func_00518E38[];
extern char func_0054D6E8[];
extern "C" void func_0020AD80(void *, void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(s32, void *, s32, void *, void *, void *);
extern "C" void func_0013F010(char *, Str *, s32);

extern "C" void func_0013EF08(void *self, void *src) {
    func_0020AD80(self, src);
    void *copy = 0;
    if (src != 0) {
        Obj *source = (Obj *)src;
        Entry *entry = source->vtable;
        copy = GT4MC__FileGT4GameData__loadInstance((s32)entry->fn, func_00518E38, 0,
                             (char *)src + entry->delta, func_0054D6E8, src);
    }
    if (copy != 0) {
        for (s32 i = 0; i < 2; ++i) {
            func_0013F010((char *)self, (Str *)((char *)copy + 0xB4 + i * 4), i);
        }
    }
}

#include "types.h"

struct Entry {
    char pad[0x10];
    s32 unk10;
};

extern "C" u16 func_00418C68(s32 arg0, s32 arg1) {
    Entry *entry = (Entry *)(arg1 * 4 + arg0);
    return *(u16 *)(arg0 + entry->unk10);
}

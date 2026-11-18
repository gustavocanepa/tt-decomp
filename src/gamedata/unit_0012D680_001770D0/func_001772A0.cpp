#include "types.h"
struct Entry { char label[64]; float score; };
extern "C" s32 func_00410A70(const char *, void *);
extern "C" void func_001772A0(s32 *indices, s32 count, Entry *entries, s32 excluded) {
    long long record[10];
    s32 i = 0;
    if (count > 0) {
      s32 *cursor = indices;
      do {
        s32 index = *cursor;
        Entry *entry = (Entry *)(index * 68 + (s32)entries);
        for (;;) {
            if (!func_00410A70(entry->label, record)) return;
            ++entry;
            s32 valid = record[7] != -1;
            if (!valid) { ++index; continue; }
            if (index == excluded) { ++index; continue; }
            ++i; break;
        }
        *cursor++ = index;
      } while (i < count);
    }
}

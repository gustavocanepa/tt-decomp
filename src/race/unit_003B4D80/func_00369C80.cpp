#include "types.h"

struct Ent { short delta; short pad; void (*fn)(char *, char *); };

extern "C" s64 func_0040CFF0(char *arg0);
extern "C" char *GT4Model__CarModel__getModelFileName(s64 arg0, char *arg1, s32 arg2, s32 arg3);

extern "C" void func_00369C80(char *arg0) {
    char buf[0x50];
    GT4Model__CarModel__getModelFileName(func_0040CFF0(arg0 + 0xFD8), buf, 1, 0);
    char *a = *(char **)(arg0 + 0x4840);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0x88);
    e->fn(a + e->delta, buf);
}

#include "types.h"

struct Entry { s32 pad; void (*fn)(s32, s32); };
extern char D_00601B40[];
extern char D_00601B60[];
extern char D_005868F8[];

extern "C" void *func_00569960(void *arg0, char *arg1, int arg2);
extern "C" void func_004A6448(const char *fmt, ...);

static inline const char *c_str(void **p) {
    s32 len = *(s32 *)((char *)*p - 0x10);
    if (len == 0)
        return D_00601B40;
    ((char *)*p)[len] = 0;
    return (char *)*p;
}

extern "C" s32 func_00443688(s32 *arg0, void **arg1, s32 arg2) {
    Entry *e = (Entry *)func_00569960((void *)c_str(arg1), D_005868F8, 1);
    if (e) {
        e->fn(*arg0, arg2);
        return 1;
    }
    func_004A6448(D_00601B60, c_str(arg1));
    return 0;
}

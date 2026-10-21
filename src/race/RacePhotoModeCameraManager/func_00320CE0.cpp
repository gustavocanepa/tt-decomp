#include "types.h"

extern "C" void func_003A67B8(void *, s32);

static inline s32 vcall378100(void *o) {
    char *ent = *(char **)o + 0x200;
    void *fn = *(void **)(ent + 4);
    return ((s32 (*)(void *))fn)((char *)o + *(s16 *)ent);
}

static inline void vcallB378100(void *o, void *x) {
    char *ent = *(char **)o + 0x68;
    void *fn = *(void **)(ent + 4);
    ((void (*)(void *, void *))fn)((char *)o + *(s16 *)ent, x);
}

extern "C" void func_00320CE0(void *arg0) {
    char *ent;
    void *fn;
    void *obj;
    if (vcall378100(arg0) == 0) {
        return func_003A67B8((char *)arg0 + 0xA80, 0);
    }
    ent = *(char **)arg0 + 0x200;
    fn = *(void **)(ent + 4);
    obj = ((void *(*)(void *, s32))fn)((char *)arg0 + *(s16 *)ent, 0);
    vcallB378100(obj, (char *)arg0 + 0xA80);
}

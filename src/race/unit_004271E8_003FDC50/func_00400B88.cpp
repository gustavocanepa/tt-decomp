#include "types.h"
struct Obj { char pad[0x40]; char buf[0x40]; };
extern "C" void func_004F8588(void *, const void *, s32);
extern "C" void func_004F83D8(void *, const void *, s32);
extern "C" s32 func_0040FBD8(s32);
extern char D_005DCFA0[];
extern char D_005FAA90[];
extern char D_005FAA98[];

static inline void setName(Obj *self, char *name) {
    if (*name == 0) {
        self->buf[0] = 0;
        return;
    }
    char *b = self->buf;
    func_004F8588(b, name, 0x40);
    s32 a = func_0040FBD8((s32)b);
    if (a == -1) {
        func_004F8588(b, D_005DCFA0, 0x40);
        func_004F83D8(b, name, 0x40);
        s32 c = func_0040FBD8((s32)b);
        if (c == a) {
            func_004F8588(b, D_005FAA90, 0x40);
            func_004F83D8(b, name, 0x40);
            if (func_0040FBD8((s32)b) == c)
                func_004F8588(b, D_005FAA98, 0x40);
        }
    }
}

extern "C" void func_00400B88(Obj *self, char *name) {
    setName(self, name);
}

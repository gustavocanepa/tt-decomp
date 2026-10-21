#include "types.h"

struct Buf {
    char *data;
    s32 len;
};

struct Obj {
    s32 a;
    Buf buf;
};

extern "C" s32 func_005683A8(char, char);
extern "C" s32 func_00568180(char *, char *, char *, char *, s32 (*)(char, char));

extern "C" s32 func_0043B510(Obj *self, char *s, s32 n) {
    Buf *b = &self->buf;
    return func_00568180(b->data, b->data + b->len - 1, s, s + n, func_005683A8);
}

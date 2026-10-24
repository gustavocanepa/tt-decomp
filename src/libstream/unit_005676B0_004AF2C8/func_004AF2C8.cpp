#include "types.h"

struct Pair {
    s32 a;
    s32 b;
    Pair() : a(0), b(0) {}
};

/* The base class; its constructor is func_004A5500. */
struct func_004A5500 {
    char pad[0x38];
    func_004A5500();
};

struct func_004AF2C8 : func_004A5500 {
    Pair m38;
    s32 m40;
    s32 m44;
    Pair m48;
    func_004AF2C8(s32 v);
};

func_004AF2C8::func_004AF2C8(s32 v) : m40(v), m44(0) {
}

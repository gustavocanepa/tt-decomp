/* basic_string<char>() out of line: dat = nilRep.grab() (clone when selfish, else ++ref). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String {
    char *dat;
    String() __asm__("func_002C1598");
};

extern StringRep D_005A4850;

extern "C" char *func_0050F0F0(StringRep *r);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_0050F0F0(r);
    ++r->ref;
    return (char *)(r + 1);
}

String::String() : dat(grab(&D_005A4850)) {
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x00615AD0.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj {
    void *u0; s32 u4, w8;
    char padC[4];
    long long u10;
    u16 u18;
    u8 u1A, u1B;
    s32 u1C, u20;
    char pad24[4];
    s32 u28;
};
extern char D_005DB5C0[];
static inline void init(Obj *o, void *a1, s32 a2) {
    o->u1A = (a1 == 0) ? 4 : 0;
    o->u0 = a1;
    o->u4 = a2;
    o->u18 = 0x20;
    o->u10 = 0x11;
    o->u1C = 6;
    o->u1B = 0;
    o->w8 = 0;
    o->u20 = 0;
}

extern "C" void func_00576B48(Obj *o, void *a1, s32 a2) {
    o->u28 = (s32)D_005DB5C0;
    init(o, a1, a2);
}

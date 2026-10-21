typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x4DC];
    u8 bits[1];
};

extern "C" void func_00406B18(Obj *o, s32 i) {
    if (i < 0x60) {
        o->bits[i >> 3] |= 1 << (i & 7);
    }
}

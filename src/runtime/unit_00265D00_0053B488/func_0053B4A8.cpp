typedef unsigned char u8;
typedef unsigned long long u64;

struct Obj { char pad[0xC8]; u8 unk9C; };

extern "C" u64 func_0053B4A8(Obj *arg0) {
    u64 v = arg0->unk9C;
    return v >> 7;
}

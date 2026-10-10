typedef unsigned long long u64;
typedef int s32;

struct Obj {
    char pad[0x8];
    u64 unk8;
} __attribute__((aligned(8)));

extern "C" s32 func_0040D6D0(Obj *arg0) {
    return ~arg0->unk8 != 0;
}

typedef unsigned int u32;
typedef unsigned long long u64;

struct Obj {
    char pad[0xA8];
    u64 unkA8;
};

extern Obj *D_005A30A8;

extern "C" void func_004F7388(u32 arg0) {
    D_005A30A8->unkA8 = (u64)arg0;
}

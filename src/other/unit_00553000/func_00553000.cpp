typedef long long s64;

struct S005F55D0 {
    char pad0[0x168];
    s64 unk168;
};

extern "C" void func_00553000(struct S005F55D0 *arg0) {
    arg0->unk168 = (arg0->unk168 & ~(0xFFLL << 16)) | (1LL << 16);
}

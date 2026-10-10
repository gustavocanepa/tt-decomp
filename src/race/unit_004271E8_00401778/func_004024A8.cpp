typedef unsigned int u32;

struct BitSet {
    u32 unk0;
    u32 bits[1];
};

extern "C" void func_00402478(BitSet *self, int a, u32 n);

extern "C" bool func_004024A8(BitSet *self, int a, u32 n) {
    func_00402478(self, a, n);
    return (self->bits[n >> 5] & (1 << (n & 31))) != 0;
}

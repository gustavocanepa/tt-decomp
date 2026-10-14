typedef int s32;

struct Block {
    char data[0x28];
};

extern "C" void func_004F6678(Block *b, s32 i, s32 n);

extern "C" Block *func_004A46F8(Block *out) {
    Block b;
    func_004F6678(&b, 0, 0x28);
    *out = b;
    return out;
}

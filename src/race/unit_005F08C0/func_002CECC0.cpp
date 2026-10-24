struct Block {
    long w[0x102];
};

struct Obj {
    char pad[0xD200];
    Block block;
};

extern "C" void func_002CECC0(Obj *o, const Block *b) {
    o->block = *b;
}

struct Block {
    long w[0x102];
};

struct Obj {
    char pad[0x8A0];
    Block block;
};

extern "C" void func_00562798(Obj *o, const Block *b) {
    o->block = *b;
}

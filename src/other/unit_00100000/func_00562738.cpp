struct Block {
    long w[0x102];
};

struct Obj {
    char pad[0x90];
    Block block;
};

extern "C" void func_00562738(Obj *o, const Block *b) {
    o->block = *b;
}

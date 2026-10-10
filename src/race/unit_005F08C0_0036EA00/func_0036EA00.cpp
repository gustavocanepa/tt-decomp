struct Block {
    long w[0x32];
};

struct Obj {
    char pad[0x138];
    Block block;
};

extern "C" void func_0036EA00(Obj *o, const Block *b) {
    o->block = *b;
}

struct Block {
    int w[12];
};

struct Obj {
    char pad[0x11D0];
    Block b;
};

extern "C" void func_00559B58(Obj *o, const Block *b) {
    o->b = *b;
}

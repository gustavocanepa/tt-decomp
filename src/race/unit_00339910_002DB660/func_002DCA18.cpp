struct Buf {
    char *base;
    int m4;
    char *cur;
};

struct Cursor {
    int m0;
    int pos;
    int end;
    int mC;
};

extern "C" void func_004242C0(Cursor *c, Buf *b);
extern "C" int func_00423FE8(Cursor *c, const char *tag);
extern "C" void GT4Model__BinStreamReader__readArray(Buf *b, const char *name, int len);
extern "C" void func_004243E0(Cursor *c, Buf *b);
extern const char D_005F2AD8[];

extern "C" void func_002DCA18(Buf *b, const char *name) {
    Cursor c;
    func_004242C0(&c, b);
    if (!func_00423FE8(&c, D_005F2AD8)) {
        b->cur = b->base + c.pos;
        return;
    }
    if (name)
        GT4Model__BinStreamReader__readArray(b, name, c.end - 8);
    func_004243E0(&c, b);
}

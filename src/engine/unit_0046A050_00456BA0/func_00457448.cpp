struct Writer;

extern "C" void func_0045A3A8(Writer *w, int v);
extern "C" void func_0045A330(Writer *w, int v);
extern int D_00602718[64];

struct Encoder {
    char pad[0x85C];
    char writer[1];
};

extern "C" void func_00457448(Encoder *e, const int *table, int id) {
    Writer *w = (Writer *)e->writer;
    func_0045A3A8(w, 0xFFDB);
    func_0045A3A8(w, 0x43);
    func_0045A330(w, id);
    for (int i = 0; i < 64; i++)
        func_0045A330(w, table[D_00602718[i]]);
}

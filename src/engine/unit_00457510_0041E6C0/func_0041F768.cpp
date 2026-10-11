struct V3 {
    float x, y, z;
};

struct Group {
    char pad[0x14];
    void *parts[5];
};

extern "C" void func_0041EEC8(V3 *v);
extern "C" void func_0041F598(void *part, V3 *v, int a, int b, int c, int d);

extern "C" void func_0041F768(Group *g, V3 *v, int a, int b, int c, int d)
{
    func_0041EEC8(v);
    for (int i = 0; i < 5; i++) {
        func_0041F598(g->parts[i], &v[i], a, b, c, d);
    }
}

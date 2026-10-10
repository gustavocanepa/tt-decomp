struct Font {
    char pad0[0x150];
    short size;
    char pad152[3];
    unsigned char id;
};

struct Layout {
    int v[4];
};

extern "C" void func_002F8C40(Font *f, const char *text, Layout *out, int flags);
extern "C" void func_002F8F28(int id, Layout *layout, int x, int y);

extern "C" void func_002F9050(Font *f, const char *text, short size, int x, int y)
{
    Layout layout;
    short saved = f->size;
    f->size = size;
    func_002F8C40(f, text, &layout, 0);
    func_002F8F28(f->id, &layout, x, y);
    f->size = saved;
}

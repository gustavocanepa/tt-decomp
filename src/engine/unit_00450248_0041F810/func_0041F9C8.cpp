/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Span {
    char pad0[4];
    unsigned short start;
    unsigned short length;
};

struct Layout {
    char pad0[0x20];
    unsigned short count20;
    unsigned short count22;
    unsigned short count24;
    unsigned short count26;
    char pad28[0x36 - 0x28];
    short size;
    char pad38[0x4C - 0x38];
    Span *spans4C;
    Span *spans50;
};

extern "C" short func_0041F9C8(Layout *self)
{
    if (self->size <= 0) {
        int size = (self->count20 + self->count22 + self->count24) * 4 + 0x20;
        int max = 0;
        unsigned int i;
        for (i = 0; i < self->count24; i++) {
            int end = self->spans4C[i].length + self->spans4C[i].start;
            if (max < end) max = end;
        }
        for (i = 0; i < self->count26; i++) {
            int end = self->spans50[i].length + self->spans50[i].start;
            if (max < end) max = end;
        }
        size += max * 4;
        self->size = size;
    }
    return self->size;
}

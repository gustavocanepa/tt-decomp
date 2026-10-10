typedef int s32;

struct Entry {
    s32 id;
    s32 unk4;
    s32 unk8;
};

extern Entry D_005E7920[];

extern "C" Entry *func_001A5410(s32 id) {
    Entry *e = D_005E7920;
    s32 i;

    for (i = 0; i < 0x48; i++, e++) {
        if (id == e->id) {
            return e;
        }
    }
    return 0;
}

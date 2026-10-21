struct Entry {
    const char *name;
    int f4;
};

struct Obj {
    char pad0[0x2A];
    unsigned short n;
    char pad1[0x2C];
    Entry *table;
};

extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" Entry *func_005670D8(const char *, Entry *, int);

extern "C" Entry *ModelSet2__searchModelName(Obj *self, const char *name, int *count)
{
    if (count != 0) {
        *count = 0;
    }
    if (self->table == 0) {
        return 0;
    }
    Entry *r = func_005670D8(name, self->table, self->n);
    if (count != 0 && r != 0) {
        *count = 1;
        Entry *end = self->table + self->n;
        Entry *e = r + 1;
        while (e != end) {
            int c = func_004A8268(e->name, name);
            e++;
            if (c != 0) {
                break;
            }
            *count += 1;
        }
    }
    return r;
}

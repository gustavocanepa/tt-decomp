struct Entry {
    char pad[9];
    unsigned char used;
    signed char index;
    char padB[5];
};

struct Table {
    unsigned int count;
    short m4;
    char pad6[0xA];
    Entry entries[1];
};

extern "C" void func_003FE6A8(Table *t);

extern "C" void func_003FE748(Table *t) {
    func_003FE6A8(t);
    t->m4 = 0;
    int n = 0;
    for (unsigned int i = 0; i < t->count; i++) {
        Entry *e = &t->entries[i];
        if (e->used)
            e->index = n++;
        else
            e->index = -1;
    }
}

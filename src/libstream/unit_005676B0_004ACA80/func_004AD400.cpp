struct Entry { int id; void *data; };
struct Table { char pad[0x30]; int next; char pad2[0x4C - 0x34]; Entry *entries; int count; };
extern "C" int func_004AD398(Table *, int);
extern "C" void *memmove(void *, const void *, unsigned int);

extern "C" Entry *func_004AD400(Table *t)
{
    int id, pos;
    do {
        id = t->next;
        if (id == 0) id++;
        t->next = id + 1;
        pos = func_004AD398(t, id);
    } while (pos >= 0);
    pos = ~pos;
    Entry *old = t->entries;
    t->entries = old - 1;
    memmove(t->entries, old, pos * sizeof(Entry));
    t->count++;
    Entry *e = &t->entries[pos];
    e->id = id;
    e->data = 0;
    return e;
}

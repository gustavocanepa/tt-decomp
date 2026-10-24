/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { char pad[0x1C]; int flags; };
struct Data { char pad[0x40]; int count; Record *records; };
struct Entry { short delta, index; Data *(*fn)(void *, int *, int); };
struct Obj { char pad[8]; char *vt; };
struct Self { char pad[0x4840]; Obj *obj; };
static inline Data *get(Obj *obj, int *out, int limit) {
    Entry *e = (Entry *)(obj->vt + 0x58);
    return e->fn((char *)obj + e->delta, out, limit);
}
static inline int flags(Data *data, int k) {
    Record *r = data->records + k;
    return r->flags;
}
extern "C" int func_003AAB10(Self *self, int *out, int limit) {
    Data *data = get(self->obj, out, limit);
    int n = data->count;
    int count = 0;
    int k = 3;
    if (k < n) {
        int *cursor = out;
        do {
            if (k != 5 && k != 20 && (flags(data, k) & 1) && count < limit) {
                *cursor = k;
                cursor++;
                count++;
            }
            k++;
        } while (k < 26 && k < n);
    }
    return count;
}

/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;
struct Vec { s32 pad; s32 *start; s32 *finish; u32 size() const { return (u32)(finish-start); } };
struct hThread {
    char pad0[0x10];
    Vec v;
    char pad1c[0x18];
    s32 u34;
};
extern "C" s32 func_002BA958(struct hThread *, u32) throw();
static inline u32 size(Vec *v) { return (u32)(v->finish - v->start); }
extern "C" s32 hThread__execute(struct hThread *self, u32 idx) {
    if (idx < self->v.size()) {
        Vec *v = &self->v;
        do {
            s32 r = func_002BA958(self, idx);
            self->u34 = r;
            if (r == 2) return r;
        } while (idx < v->size());
    }
    return self->u34;
}

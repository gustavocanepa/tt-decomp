/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct T12 { s32 a, b, c; };
struct Vec { T12 *start; T12 *finish; T12 *eos; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32); };
struct Owner { char pad[0x5C]; char *vtbl; };
struct Obj {
    Owner *owner;
    Obj *prev;
    Obj *next;
    char pad0C[0x168 - 0x0C];
    char *str168;
    char pad16C[0x174 - 0x16C];
    char sub174[8];
    char *str17C;
    Vec vec;
    char pad18C[0x18C - 0x18C];
    char sub18C[4];
};
struct Self { int a,b; void *vt; int c; void *mem; Obj *obj; };
extern char D_005D3A88[];

extern char *D_005A4C64[];
extern "C" void func_00377E90(Self *, int);
extern "C" void func_0043D510(void *);
extern "C" void func_004A45D0(void *) throw();
extern "C" void func_0050E1A8(void *) throw();

static inline void unref(char *p) {
    s32 *r = (s32 *)(p - 0x10);
    s32 v = r[2] - 1;
    r[2] = v;
    if (v == 0) func_004A45D0(r);
}

static inline void destroy_range(T12 **pf, T12 *last) {
    for (T12 *p = *pf; p != last; ++p) {
    }
}

extern "C" void RacePause__structor_1(Self *self, int flags) {
    self->vt = D_005D3A88;
    Obj *o = self->obj;
    if (o != 0) {
        func_0043D510(o->sub18C);
        Vec *v = &o->vec;
        T12 *first = v->start;
        destroy_range(&first, v->finish);
        T12 *st = v->start;
        s32 n = v->eos - st;
        if (n != 0) {
            u32 bytes = n * 12;
            if (bytes > 0x80) {
                func_004A45D0(st);
            } else {
                char **slot = &D_005A4C64[(bytes + 7) >> 3];
                *(char **)st = *slot;
                *slot = (char *)st;
            }
        }
        unref(o->str17C);
        func_0043D510(o->sub174);
        unref(o->str168);
        if (o->prev == o->next) {
            Owner *ow = o->owner;
            if (ow != 0) {
                VEntry *e = (VEntry *)(ow->vtbl + 8);
                e->fn((char *)ow + e->delta, 3);
            }
        } else {
            o->next->prev = o->prev;
            o->prev->next = o->next;
        }
        func_0050E1A8(o);
    }
    func_004A45D0(self->mem);
    func_00377E90(self, 0);
    if (flags & 1) func_0050E1A8(self);
}

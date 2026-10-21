typedef int s32;

struct Obj { char *vt; };
struct Self { char pad[0x10]; Obj *f10; };
struct Src { char pad[4]; char *vt; };
struct Buf { void *p; s32 size; };

struct V1 { short d, i; s32 (*fn)(void *); };
struct V2 { short d, i; s32 (*fn)(void *, void *); };
struct V3 { short d, i; s32 (*fn)(void *, s32, void *, s32); };

extern "C" void free(void *) throw();
extern "C" void *func_004A4690(int, int);

extern "C" s32 func_001669C8(Self *self, Src *src, s32 arg2) {
    Buf b;
    s32 r;
    {
        Obj *o = self->f10;
        V1 *v = (V1 *)(o->vt + 0x10);
        s32 sz = (v->fn((char *)o + v->d) + 0x3F) & ~0x3F;
        b.p = 0;
        b.size = sz;
        b.p = func_004A4690(0x40, sz);
        V3 *w = (V3 *)(src->vt + 0x1E0);
        r = w->fn((char *)src + w->d, arg2, b.p, sz);
    }
    if (r > 0) {
        Obj *o = self->f10;
        V2 *v = (V2 *)(o->vt + 0x18);
        if (v->fn((char *)o + v->d, b.p) != 0) {
            Obj *o2 = self->f10;
            V2 *v2 = (V2 *)(o2->vt + 0x30);
            v2->fn((char *)o2 + v2->d, b.p);
        } else {
            r = -1;
        }
    }
    free(b.p);
    return r > 0;
}

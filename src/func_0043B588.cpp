typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Local { s32 key; void *base; u8 flag; };
struct Vec { void *data; s32 count; };
struct Obj { char p0[8]; struct Vec v; };

extern void *func_00568230(void *, void *, void *, s32, s32);

extern "C" s16 func_0043B588(struct Obj *a0, s32 a1)
{
    struct Local loc;
    struct Vec *v = &a0->v;

    loc.key = a1;
    if (v->count == 0) {
        return -1;
    }
    loc.base = v->data;
    loc.flag = 0;
    void *b = func_00568230(v->data, (char *)v->data + (v->count << 2), &loc, 0, 0);
    if (b == (char *)v->data + (v->count << 2)) {
        return -1;
    }
    if (((s16 *)b)[0] == loc.key) {
        return ((s16 *)b)[1];
    }
    return -1;
}

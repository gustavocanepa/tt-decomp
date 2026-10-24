/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *); };
struct B { void *p; };
struct A { char pad[0x7c]; B *b; };
struct Data { char pad[0x18]; A *a; s32 pad2; s32 x; s32 y; };
struct Obj { char pad[8]; VEntry *vtbl; char pad2[8]; Data *data; };
extern "C" s32 func_00388FF8(void);
extern "C" Data *func_004A4690(s32, s32);
extern "C" void func_0047DB58(void *, s32, Data *, s32, s32);
extern "C" void func_0041DCD8(void *);
extern "C" void func_0041FAC8(void *, B *, s32, s32);
extern "C" void func_0041ED48(s32, s32, s32);
extern "C" void func_0041D1E8(void *, s32);
extern "C" void func_00343990(Obj *o, s32 arg) {
    s32 buf[8];
    s32 flags = func_00388FF8();
    Data *data = o->data;
    if (!data) {
        data = func_004A4690(0x40, 0xb4000);
        o->data = data;
        flags = 0xb4000;
    }
    func_0047DB58(buf, arg, data, flags, 1);
    func_0041DCD8(o->data);
    B *b = o->data->a->b;
    func_0041FAC8(b->p, b, 0, 0);
    Data *d = o->data;
    s32 y = d->y;
    s32 x = d->x;
    if (y && x) {
        VEntry *e = &o->vtbl[8];
        func_0041ED48(y, x, e->fn((char *)o + e->delta));
    }
    func_0041D1E8((char *)o + 0x18, x);
}

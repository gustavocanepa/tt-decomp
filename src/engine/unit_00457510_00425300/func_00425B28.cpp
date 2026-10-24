/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Src { char pad[0x23968]; int count; };
struct Obj { Src *src; int count; int m8; };
void func_00426400(Obj *, float);
void func_00425BE0(Obj *, int);
void func_00425D60(Obj *);

extern "C" void func_00425B28(Obj *o, Src *src, int m8)
{
    func_00426400(o, 0.0f);
    o->m8 = m8;
    o->src = src;
    o->count = src->count;
    for (int i = 0; i < o->count; i++) func_00425BE0(o, i);
    return func_00425D60(o);
}

struct Elem { char pad[0x28]; };
struct Owner { Elem *list; int m4; int m8; };
extern "C" void func_004A8D30(Elem *e, int a, int b, int c);
extern "C" int func_004A8DD0(Elem *e);

extern "C" void func_004A9200(Owner *o, int a)
{
    Elem *e = o->list;
    if (e == 0) return;
    while (!func_004A8DD0(e))
        func_004A8D30(e++, a, o->m4, o->m8);
}

struct VEntry { short delta; short index; int (*fn)(void *, void *, int); };
struct Listener { char pad[0x5C]; char *vtbl; };
struct Obj { Listener *listener; char pad[0xC]; int m10; char pad2[0x2C]; char m40[1]; };
extern "C" int func_0043D1A8(Obj *);
extern "C" void func_00443DD0(void *, int);

extern "C" int func_0043D0C8(Obj *o, int c)
{
    if (o->m10 && c == 13 && func_0043D1A8(o)) return 1;
    func_00443DD0(o->m40, c);
    Listener *l = o->listener;
    if (l) {
        VEntry *e = (VEntry *)(l->vtbl + 0x30);
        return e->fn((char *)l + e->delta, o, 0x80);
    }
    return 0;
}

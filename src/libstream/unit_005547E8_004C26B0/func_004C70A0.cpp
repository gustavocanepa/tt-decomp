struct Item { char pad[0x30]; int type; };
struct Handler { void (*fn)(Item *); int a, b; };
struct Mgr { char pad[0x50]; Handler handlers[1]; };
extern char D_005A0B88[];
extern "C" void func_004A4930(void *);
extern "C" void func_004A4970(void *);
extern "C" void func_004C7260(Mgr *, Item *);

extern "C" void func_004C70A0(Mgr *m, Item *it, int flag)
{
    func_004A4930(D_005A0B88);
    Handler *h = m->handlers;
    h += it->type;
    void (*fn)(Item *) = h->fn;
    if (fn) fn(it);
    if (flag) func_004C7260(m, it);
    func_004A4970(D_005A0B88);
}

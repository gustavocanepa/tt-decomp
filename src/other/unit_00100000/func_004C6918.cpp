struct Chan { int open; int pad[4]; int count; };
struct Dev { char pad[0x234]; Chan chan; };
extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" char D_005A0B88[];

extern "C" int func_004C6918(Dev *d)
{
    Chan *c = &d->chan;
    if (!c->open)
        return 0;
    func_004A4930(D_005A0B88);
    int n = c->count;
    func_004A4970(D_005A0B88);
    return n;
}

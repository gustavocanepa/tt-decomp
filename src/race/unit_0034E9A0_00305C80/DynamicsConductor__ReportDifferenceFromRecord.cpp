struct Ctx { char pad[0x5D7]; unsigned char paused; };
struct Clock { char pad[0x968]; int start; };
struct Obj {
    Clock *clock;
    char pad[0x20A24 - 4];
    unsigned char frozen;
};
extern "C" Ctx *func_002F04D8(Obj *o, int a);
extern "C" void func_003053E8(Clock *c, int a, int dt);

extern "C" void DynamicsConductor__ReportDifferenceFromRecord(Obj *o, int a, int t)
{
    if (o->frozen)
        return;
    if (func_002F04D8(o, a)->paused)
        return;
    Clock *c = o->clock;
    if (c->start != 0x157529FF)
        func_003053E8(c, a, t - c->start);
}

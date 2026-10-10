struct Tm { unsigned short year; unsigned char month, day, hour, min, sec, pad; };
struct Stamp { unsigned char flag, sec, min, hour, day, month; unsigned short year; } __attribute__((aligned(8)));
struct Obj { int m0, m4; Stamp now; Stamp saved; char pad[0x48 - 0x18]; unsigned short flags; };
extern "C" int func_004B6658(void);
extern "C" void func_004AF960(Tm *, int);
extern "C" void *func_004F6678(void *, int, unsigned int);

extern "C" void func_0019B4B8(Obj *o)
{
    Tm t;
    func_004AF960(&t, func_004B6658());
    func_004F6678(&o->now, 0, 0x40);
    o->now.flag = 0;
    o->now.sec = t.sec;
    o->now.min = t.min;
    o->now.hour = t.hour;
    o->now.day = t.day;
    o->now.month = t.month;
    o->now.year = t.year;
    o->saved = o->now;
    o->flags |= 4;
}

extern "C" unsigned int func_004A8368(const char *s);
struct String2;
extern "C" String2 *func_0050F1B0(String2 *str, unsigned int pos, unsigned int n1, const char *s, unsigned int n2);
struct String2 {
    char *dat;
    String2 &replace(unsigned int pos, unsigned int n1, const char *s, unsigned int n2) { return *func_0050F1B0(this, pos, n1, s, n2); }
    String2 &assign(const char *s, unsigned int n) { return replace(0, (unsigned int)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_004A8368(s)); }
};

struct Part;
extern "C" void func_0047F880(Part *p);
extern "C" char D_005F0E20[];

struct Obj {
    char pad[0x14];
    String2 name;
    char part[0xD0];
    int mE8;
    int mEC;
    int mF0;
    int mF4;
};

extern "C" void hFileIO__virtual_53(Obj *o)
{
    func_0047F880((Part *)o->part);
    o->mE8 = 0;
    o->mF0 = 0;
    o->mF4 = 0;
    o->name.assign(D_005F0E20);
}

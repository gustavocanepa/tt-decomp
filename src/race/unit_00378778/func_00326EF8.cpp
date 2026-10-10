/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Src { char pad[0xC]; short mC; };
struct func_00321898 {
    func_00321898(const Src *s);
    char pad[0x18C];
};
struct func_0032DE18 {
    func_0032DE18();
    int d[3];
};
extern "C" void *func_004F6678(void *p, int c, unsigned int n);

struct Obj {
    char pad0[0xE8];
    int mE8;
    char pad1[0x148 - 0xEC];
    int m148;
    char pad2[0x180 - 0x14C];
    unsigned long m180;
};
struct func_00326EF8 : func_00321898 {
    func_0032DE18 a;
    func_0032DE18 b;
    char z[12];
    int m1B0;
    func_00326EF8(const Src *s);
};

func_00326EF8::func_00326EF8(const Src *s) : func_00321898(s)
{
    func_004F6678(z, 0, 12);
    Obj *o = (Obj *)this;
    o->m180 &= ~0xFFUL;
    *(int *)&o->pad2[0x184 - 0x14C] = s->mC;
    o->m148 = 7;
    m1B0 = 0;
    o->mE8 = 1;
}

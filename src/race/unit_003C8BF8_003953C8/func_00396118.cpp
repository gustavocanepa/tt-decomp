/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00394998(char *) throw();
extern "C" void Pitmen__StatusEntity__clear(char *) throw();
extern "C" void Pitmen__StatusCategory__clear(char *) throw();
extern "C" void func_00394B10(char *) throw();
extern "C" void Pitmen__Camera__clear(char *) throw();
extern "C" void func_003991E0(char *);
extern "C" void func_003D0E78(char *);
extern "C" void func_003CA210(char *);
extern "C" void PitinPillar__clear(char *);
extern "C" int func_0042DCF8(char *);
extern "C" void func_00396118(char *o)
{
    char *p;
    char *q;
    int i, j, k;
    Pitmen__Camera__clear(o + 4);
    p = o + 0x2C4;
    i = 5;
    do {
        PitinPillar__clear(p);
        p += 0x30;
    } while (--i != -1);
    q = o + 0x3E4;
    j = 5;
    do {
        p = q;
        k = 5;
        do {
            func_003CA210(p + 0x1C);
            Pitmen__StatusEntity__clear(p);
            p += 0x178;
        } while (--k != -1);
        q += 0x8D0;
    } while (--j != -1);
    p = o + 0x38C4;
    i = 5;
    do {
        func_00394998(p + 4);
        Pitmen__StatusCategory__clear(p);
        p += 0xAA4;
    } while (--i != -1);
    p = o + 0x789C;
    i = 5;
    do {
        func_00394B10(p);
        p += 0xA4;
    } while (--i != -1);
    func_003D0E78(o + 0x7C74);
    func_0042DCF8(o + 0x9900);
    *(int *)(o + 0x9920) = 1;
    *(int *)(o + 0x96E4) = -0x10;
    return func_003991E0(o);
}

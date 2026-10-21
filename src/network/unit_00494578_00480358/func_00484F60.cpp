/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rng {
    char pad0[4];
    short a;
    short b;
};
struct Ent2 {
    char k;
    char pad1[3];
    int b;
};
struct Side {
    int kind;
    char pad4[0x210];
    int w214;
    Ent2 ents[0x40];
    int w418;
};
struct Obj {
    char pad0[0x24];
    char sides[0x41C];
    char pad43C[0x41C];
    char pad858[0];
};
struct Root {
    char pad0[0x24];
    char body[0x838];
    int w858;
    char pad85C[4];
    int w860;
};
extern "C" Rng *func_004834E8(Root *) throw();
extern "C" Rng *func_00483528(Root *) throw();
extern "C" void func_004838C8(Root *, void *, void *) throw();
extern "C" void func_00484050(Root *, int) throw();
extern "C" void func_00484360(Root *) throw();

extern "C" int func_00484F60(Root *o) {
    if (o->w860 != 0) return 1;
    {
        Side *s1 = (Side *)((char *)o + (1 - o->w858) * 0x41C + 0x24);
        Rng *s3 = func_004834E8(o);
        Rng *s4 = func_00483528(o);
        switch (s1->kind) {
        case 0:
            func_004838C8(o, s3, s4);
            return 1;
        case 1:
            if (s3->b == s3->a && s4->b == s4->a) {
                int n = s1->w418;
                int i2 = n + 2;
                int i1 = n - 1;
                func_004838C8(o, s4, &s1->ents[i2]);
                func_004838C8(o, s3, s4);
                func_004838C8(o, &s1->ents[i1], s3);
            } else {
                func_004838C8(o, s3, s4);
                func_00484050(o, 1);
            }
            return 1;
        case 2:
            if (s1->w418 < s1->w214 - 1) {
                Ent2 *e = &s1->ents[s1->w418];
                char v = e[1].k;
                if (v == 2) {
                    *(char *)s3 = v;
                    s1->w418 = s1->w418 + 1;
                    func_00484360(o);
                }
            }
            return 1;
        default:
            return 1;
        }
    }
    return 1;
}

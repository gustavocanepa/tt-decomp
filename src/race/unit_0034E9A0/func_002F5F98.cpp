/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[1]; unsigned char m1; };
struct Slot {
    float m0; char p0[0x28 - 4]; float m28; float m2C;
    char p1[0x89 - 0x30]; unsigned char m89;
    char p2[0xF4 - 0x8A];
};
struct Self { char p[0x10]; void *m10; char q[0x164 - 0x14]; Slot s[8]; };
extern "C" Obj *func_002FD378(void *);
extern "C" void *func_00308058(void *, int, int);
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
extern "C" void func_002F5C18(Slot *, void *, void *, float) throw();

extern "C" void func_002F5F98(Self *self) {
    unsigned i = 0;
    void *d = self->m10;
    Obj *o = func_002FD378(d);
    if (__builtin_expect(o->m1, 0)) {
        Slot *p = self->s;
        do {
            void *it = func_00308058(d, i, p->m89);
            i++;
            float a = p->m0;
            float x = func_004A5C50(a) * p->m28;
            float y = func_004A5D18(a) * p->m2C;
            Slot *q = p;
            p++;
            func_002F5C18(q, d, it, x - y);
        } while (i < o->m1);
    }
}

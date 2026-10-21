/* compiler: ee-gcc2.96-nogcse */
struct Ent {
    unsigned short id;
    unsigned short type;
    float f4, f8, fC;
};
struct Group {
    unsigned short n;
    unsigned short pad;
    Ent e[1];
};
struct Item {
    float f0, f4;
    int f8, fC;
};
struct ItemTab { Item it[1]; };
struct Obj {
    char pad0[0x10];
    unsigned short count;
    char pad12[6];
    Group **groups;
    char pad1C[8];
    ItemTab *items;
    int *tab;
};

extern float D_00769CD0[];

extern "C" {
void func_00469BB0(int, int, int, int, int);
void func_00469BF0();
void func_0046A0D8(int, float *, int, int, int, int);
void func_0046AEA0(int);
void func_0046B668(int);
float *func_00473980(int);
}

static inline Item *item_at(Obj *o, unsigned n) { ItemTab *b = o->items; return b->it + n; }

extern "C" void BillboardSet__render(Obj *o, int idx) {
    if (o == 0) return;
    if (idx >= o->count) return;
    Group *g = o->groups[idx];
    if (g == 0) return;
    Ent *e = g->e;
    unsigned fp = 0;
    int i = 0;
    int func_005AE360 = 0;
    if (g->n != 0) {
        do {
            unsigned t = e->id;
            if (t & 0x8000) {
                if (func_005AE360 != 0) {
                    func_005AE360 = 0;
                    func_00469BF0();
                }
                fp = 0;
                t &= 0xFFFF7FFF;
                func_0046B668(o->tab[t]);
            } else {
                Item *it = item_at(o, t);
                if (fp != e->type) {
                    if (func_005AE360 != 0) {
                        func_005AE360 = 0;
                        func_00469BF0();
                    }
                    func_0046AEA0(e->type);
                    fp = e->type;
                }
                float *v = func_00473980(3);
                float t6 = e->f4 + D_00769CD0[0] * it->f0;
                v[9] = t6;
                float t7 = e->f8;
                v[10] = t7;
                float t5 = e->fC + D_00769CD0[2] * it->f0;
                v[11] = t5;
                float t3 = e->f4 - D_00769CD0[0] * it->f0;
                v[3] = t3;
                float t4 = e->f8;
                v[4] = t4;
                float t2 = e->fC - D_00769CD0[2] * it->f0;
                v[5] = t2;
                v[6] = t6;
                v[7] = t7 + it->f4;
                v[8] = t5;
                v[0] = t3;
                v[1] = t4 + it->f4;
                v[2] = t2;
                if (func_005AE360 == 0) {
                    func_005AE360 = 1;
                    func_00469BB0(4, 0x32, 0x31, 0x27, 0x32);
                }
                func_0046A0D8(4, v, it->f8, it->fC, 0, 0);
            }
            i++;
            e++;
        } while (i < g->n);
    }
    if (func_005AE360 != 0) {
        func_00469BF0();
    }
}

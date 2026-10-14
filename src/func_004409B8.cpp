/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

struct Slot {
    char pad0[4];
    s32 unk4;
    char pad8[0xA];
    s16 unk12;
};
struct Table {
    char pad[0x50];
    char *items;
};
struct Obj81168 {
    s32 (*unk0)(s32);
    s32 unk4;
};
struct Ctx {
    char pad0[0x6E14];
    void *anim;
    char unk6E18[8];
    Table *t;
    char pad6E24[0x14];
    s32 unk6E38;
    char pad6E3C[0x44];
    Obj81168 unk6E80;
};
struct S {
    float x0;
    float y0;
    float x1;
    float y1;
    char unk10[4];
    s16 idx;
    u16 w;
    char pad18[3];
    u8 unk1B;
    char pad1C[6];
    s16 unk22;
};

extern "C" s32 func_00447EC8(Obj81168 *, s32);
extern "C" u32 func_00445370(const unsigned char *, const unsigned char *);
extern "C" void func_00439EC8(void *, u32) throw();
extern "C" void func_00440518(Slot *, Ctx *, float) throw();
extern "C" void func_0043A448(void *, float, float, float, float) throw();
extern "C" void func_0043A3E8(void *, s32) throw();
extern "C" void func_0043A568(void *, char *, s32) throw();
extern "C" s32 func_00440578(Slot *) throw();
extern "C" void func_004755EC(float, float, float);
extern "C" void func_00475638(float, float, float);
extern "C" void func_00445628(Ctx *);
extern "C" float func_00440E50(S *, Ctx *, char **);
extern "C" float func_00440C48(S *, Ctx *, char **);

extern "C" void func_004409B8(S *a, Ctx *c, char *str, s32 flag) {
    char *p = str;
    if (a->idx >= 0) {
        if (flag != 0) {
            p = (char *)func_00447EC8(&c->unk6E80, (s32)p);
        }
        c->unk6E38 = 1;
        func_00439EC8(c->anim, func_00445370((const unsigned char *)c->unk6E18, (const unsigned char *)a->unk10));
        Slot *e = (Slot *)(c->t->items + a->idx * 0x18);
        if (e->unk4 == 0) {
            func_00440518(e, c, (float)a->w * 0x1.999998p-5f);
            float x0 = a->x0;
            float y0 = a->y0;
            func_0043A448(c->anim, x0, y0, a->x1 - x0, a->y1 - y0);
            s32 k;
            s32 t = a->unk1B;
            switch(t) {
            case 1: k = 1; break;
            case 2: k = 2; break;
            case 3: k = 3; break;
            case 0: default: k = 0; break;
            }
            func_0043A3E8(c->anim, k);
            func_0043A568(c->anim, p, -1);
            c->unk6E38 = 0;
        } else {
                        float sc = (float)a->w * 0x1p-10f;
            float k05 = 0x1.999998p-5f;
            func_004755EC(0.0f, (float)e->unk12 * k05 * sc, 0.0f);
            func_00475638(sc, sc, 0.0f);
            func_00445628(c);
            float f = 0.0f;
            if (*p != 0) {
                float k512 = 0x1.999998p+5f;
                s32 cr = 13;
                while (*p != 0) {
                    if (*p == cr) {
                        float nf = -f;
                        func_004755EC(nf, (float)func_00440578(e) * k05 + ((float)a->unk22 * k512) / (float)a->w, 0.0f);
                        f = 0.0f;
                    } else {
                        if (a->unk1B == 0) {
                            f = func_00440E50(a, c, &p);
                        } else {
                            f = func_00440C48(a, c, &p);
                        }
                    }
                    p++;
                }
            }
            c->unk6E38 = 0;
        }
    }
}

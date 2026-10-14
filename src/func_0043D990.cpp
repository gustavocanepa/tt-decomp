/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};
struct Str {
    char *p;
};
struct Val {
    s32 type;
    s32 v;
};
struct Node {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s8 unkC;
    char padD[0x3];
    s32 unk10;
    char pad14[0x4];
    Val val;
};
struct Obj5 {
    char pad[0x164];
    void *unk164;
};
struct Obj3 {
    char pad[8];
    s32 unk8;
};

extern char D_005A4C58[];
extern char D_00601478[];

extern "C" void func_0043D510(Val *) throw();
extern "C" void func_0043D3B8(Val *, Val *) throw();
extern "C" void *func_0043D3E0(void *, void *) throw();
extern "C" void func_0043D438(Val *) throw();
extern "C" s32 func_0043DEE8(Val *);
extern "C" s32 func_00441570(s32);
extern "C" void func_00447CD8(void *);
extern "C" void func_00447D00(void *, s32);
extern "C" void *func_00448048(void *, Str *);
extern "C" void func_004A45D0(void *) throw();
extern "C" s32 func_004A4690(s32, s32);
extern "C" s32 func_004A6500(char *, const char *, ...);
extern "C" s32 func_004A8368(const char *) throw();
extern "C" s32 exception__structor_0(s32);
extern "C" char *strobe__toUpper(void *);
extern "C" void *func_00550E18(void *, u32, u32, const char *, u32);

struct StrT {
    char *p;
    char pad[0xC];
};

extern "C" void func_004412F0(s32 *, s32, s32, Val *, u32, s32, void *);

extern "C" void func_0043D990(Val *arg0, Val *arg1, s32 arg2, u32 arg3, s32 arg4, Obj5 *arg5) {
    char buf[16];
    s32 tmp[4];
    StrT str;
    struct ByteTag { s8 value; } b1;
    void *s5 = arg5->unk164;
    s32 type = 7;
    func_0043D510(arg0);
    arg0->type = type;
    s32 v_s1 = exception__structor_0(0x20);
    Node *v_s0 = (Node *)(v_s1 + 4);
    *(s32 *)v_s1 = 0;
    b1.value = 0;
    u8 *p_s0 = (u8 *)&b1;
    v_s0->unk4 = 0;
    s32 t1 = func_004A4690(0x10, 0x1c);
    v_s0->unk8 = 0;
    v_s0->unk4 = t1;
    v_s0->unkC = *p_s0;
    *(s32 *)t1 = 0;
    *(s32 *)(v_s0->unk4 + 4) = 0;
    *(s32 *)(v_s0->unk4 + 8) = v_s0->unk4;
    *(s32 *)(v_s0->unk4 + 0xc) = v_s0->unk4;
    v_s0->unk10 = 0;
    Val *s2 = (Val *)(v_s1 + 0x18);
    func_0043D3B8(s2, arg1);
    func_0043D438(s2);
    if ((arg1->type ^ 13) == 0) {
        v_s0->unk10 = func_00441570(func_0043DEE8(s2));
    }
    arg0->v = v_s1;
    switch (arg1->type) {
    case 13: {
        s32 *pt = tmp;
        s32 value = func_0043DEE8(arg1);
        func_004412F0(pt, value, arg2, arg0, arg3, arg4, arg5);
        func_0043D510((Val *)pt);
        break;
    }
    case 15: {
        u32 i = 0;
        if (arg3 != 0) {
            StrT *pk = &str;
            do {
                func_004A6500(buf, D_00601478, i);
                void *m = (void *)(arg0->v + 4);
                StrT *ps = &str;
                char *src = buf;
                Rep *g = (Rep *)D_005A4C58;
                char *r;
                if (g->sel != 0) {
                    r = strobe__toUpper(g);
                } else {
                    r = (char *)g + 0x10;
                    g->ref++;
                }
                ps->p = r;
                func_00550E18(ps, 0, (u32)-1, src, func_004A8368(src));
                void *v = func_00448048(m, (Str *)pk);
                func_0043D3E0(v, (void *)(((Obj3 *)s5)->unk8 - 8));
                Rep *q = (Rep *)(pk->p - 0x10);
                if (--q->ref == 0) func_004A45D0(q);
                func_00447CD8(s5);
                i++;
            } while (i < arg3);
        }
        break;
    }
    default:
        func_00447D00(s5, arg3);
        break;
    }
}

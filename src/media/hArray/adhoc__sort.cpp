typedef int s32;
struct H { s32 p; s32 pad[3]; };
struct W { char *vp; char sub[4]; int pad[2]; };
extern char D_005C3A80[], D_005A65B0[], D_005C38A8[];
extern "C" void func_002931C8(void *, int) throw();
extern "C" void func_00293220(void *, s32) throw();
extern "C" void func_002958F0(s32, W *);
extern "C" void func_0029B470(void *, void *);
extern "C" void func_0029B488(void *, int);
extern "C" void func_0029B4E0(void *, void *);

static inline void finish(H *it, W *o, char *v) { o->vp=v; func_002931C8(it,2); }
extern "C" void adhoc__sort(void *self, s32 unused, s32 sel, void *arg3) {
    H it;
    if (sel == 0) {
        W o;
        func_00293220(&it, unused);
        char *bv = D_005A65B0;
        W *po = &o;
        s32 itp = it.p;
        po->vp = D_005C3A80;
        func_002958F0(itp, po);
        finish(&it, po, bv);
    } else if (sel == 1) {
        H s20;
        W s30;
        func_00293220(&it, unused);
        char *bv = D_005A65B0;
        H *p20 = &s20;
        func_0029B4E0(p20, arg3);
        W *p30 = &s30;
        s32 itp = it.p;
        char *p34 = p30->sub;
        char *v2 = D_005C38A8;
        p30->vp = v2;
        func_0029B470(p34, p20);
        func_002958F0(itp, p30);
        p30->vp = v2;
        func_0029B488(p34, 2);
        p30->vp = bv;
        func_0029B488(p20, 2);
        func_002931C8(&it, 2);
    }
}

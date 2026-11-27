/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct VEntry { short delta; short index; s32 (*fn)(void *, s32); };
struct Item { char pad0[0x10]; Item *next; s32 f14; char pad18[8]; char name[1]; };
struct List { s32 count; char pad4[4]; void **p8; char padC[8]; Item *head; };
struct Cfg { char pad[0x5D6]; u8 b5B6; };
struct Gx { char pad[0x18]; Cfg *p18; };
struct G0 { Gx *p0; };
struct List2 { s32 count; char pad4[4]; G0 *p8; char padC[8]; Item *head; };
struct Fp { char pad[0x60]; List2 *p60; char pad64[0xC]; void *p70; };
struct A2 { char pad[0x6C]; Fp *p6C; };
struct Obj { char pad[0x134]; char *vt; };
struct A0 { char pad0[4]; char names[0x300]; char pad304[0]; };

extern "C" void func_00112AB8(char *, Obj *, A2 *);
extern "C" void func_0036C1E8(void *);
extern "C" char *func_0040CF70(char *);
extern "C" s32 func_0040D640(void *, void *);
extern "C" s32 func_0040F140(void *, s32);
extern "C" char *func_004F7B74(char *, const char *);

extern "C" void func_00112948(char *arg0, Obj *arg1, A2 *arg2) {
    Fp *fp = arg2->p6C;
    List2 *l = fp->p60;
    s32 i;
    Item *it;
    char *c0, *c1;
    s32 *c2, *c3;
    if (l->p8->p0->p18->b5B6 == 0) {
        func_00112AB8(arg0, arg1, arg2);
        return;
    }
    i = 0;
    func_0036C1E8(fp->p60);
    it = fp->p60->head;
    if (fp->p60->count > 0) {
        c3 = (s32 *)(arg0 + 0x364);
        c2 = (s32 *)(arg0 + 0x37C);
        c1 = arg0 + 0x304;
        c0 = arg0 + 4;
        do {
            char *nm = (char *)it + 0xFD8;
            func_004F7B74(c0, func_0040CF70(nm));
            c0 += 0x80;
            func_0040D640(nm, c1);
            c1 += 0x10;
            if (it->f14 == 0) *(s32 *)(arg0 + 0x4A4) = i;
            *c2 = func_0040F140(fp->p70, i++);
            c2++;
            VEntry *e = (VEntry *)(arg1->vt + 0x60);
            *c3 = e->fn((char *)arg1 + e->delta, it->f14);
            c3++;
            it = it->next;
        } while (i < fp->p60->count);
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; s32 (*fn)(void *, s32); };
struct VObj { char pad[4]; char *vt; };
struct H { VObj *p; char pad[0xC]; };
struct W { s32 v; char pad[0xC]; };
extern "C" void func_001DF1F8(void *, int);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_00269EE8(void *, int) throw();
extern "C" void func_00269F40(void *, s32) throw();
extern "C" void func_0026C520(s32, s32, s32 *, s32);
extern "C" void func_002931C8(void *, int);
extern "C" void func_00293220(void *, void *);
extern "C" s32 func_00294F40(void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029CF48(void *, s32);
extern "C" int func_0029E9F0(s32);
extern "C" void free(void *) throw();
extern "C" s32 *malloc(s32) throw();
extern "C" void func_0026A6A8(void *arg0, s32 arg1, s32 n, char *list) {
    if (n < 2) return;
    s32 sp0[4];
    H arr;
    W w;
    func_001DF250(sp0, list);
    H *pa = &arr;
    s32 i = 0;
    func_00293220(pa, list + 4);
    s32 cnt = func_00294F40(pa->p);
    s32 *buf = malloc(cnt * 4);
    W *pw;
    if (cnt > 0) {
        pw = &w;
        s32 *q = buf;
        do {
            W *lw = &w;
            VObj *o = pa->p;
            E *e = (E *)(o->vt + 0x88);
            s32 idx = i;
            i++;
            func_0029CF48(lw, e->fn((char *)o + e->d, idx));
            *q = func_0029E9F0(lw->v) != 0;
            q++;
            func_0029CEF0(lw, 2);
        } while (i < cnt);
    } else {
        pw = &w;
    }
    func_00269F40(pw, arg1);
    func_0026C520(pw->v, sp0[0], buf, cnt);
    func_00269EE8(pw, 2);
    free(buf);
    func_002931C8(pa, 2);
    func_001DF1F8(sp0, 2);
}

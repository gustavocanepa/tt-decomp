/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; void (*fn)(void *, void *, s32, void *); };
struct VObj { char pad[4]; char *vt; };
struct S {
    char pad0[0xEC]; VObj *h; char padd4[0x8]; s32 dc; char pade0[0x1C]; s32 fc; s32 f100; s32 f104;
};
struct Cur { void *p; char pad[0xC]; };
extern char D_005EF660[];
extern "C" s32 func_001E5440(s32, s32);
extern "C" void func_001E9558(void *, void *);
extern "C" void func_001EDBE0(void *, int);
extern "C" void func_001EEB30(void *, char *);
extern "C" void func_001EEDE8(void *);
extern "C" void *func_00210118(void *);
extern "C" s32 func_001D9CC0(void *);
extern "C" void func_0026AB58(void *, s32) throw();
extern "C" void func_0026B7B0(void *, s32) throw();
extern "C" void func_002A7578(void *, void *);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A7A30(void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_004AC580(void *, s32);
extern "C" void func_0026BD80(S *self, s32 arg1, s32 arg2) {
    {
        Cur c;
        func_001EEDE8(&c);
        func_001EEB30(c.p, D_005EF660);
        func_001EDBE0(&c, 2);
    }
    if (arg2 == 0)
        func_0026AB58(self, arg1);
    else
        func_004AC580((char *)self + 0xF4, self->f100);
    func_001E9558(func_00210118(self), self);
    func_001E5440(arg1, 0);
    self->fc = 0;
    self->f104 = 0;
    if (arg2 == 0)
        func_0026B7B0(self, arg1);
    if (func_001D9CC0(self) != 0) {
      VObj **hp = &self->h;
      if (*hp != 0) {
        char h0[0x10];
        s32 rbuf[4];
        s32 tbuf[4];
        s32 v;
        func_002A7A30(h0);
        s32 *r = rbuf;
        func_002A7A30(r);
        s32 *t = tbuf;
        v = arg1;
        func_002A7578(t, &v);
        if (r != t) {
            s32 nv = t[0];
            if (nv != 0) func_002C0FE8(nv);
            if (r[0] != 0) func_002C1050(r[0]);
            r[0] = nv;
        }
        func_002A75A8(t, 2);
        VObj *o = *hp;
        E *e = (E *)(o->vt + 0xC0);
        e->fn((char *)o + e->d, h0, 1, r);
        s32 *p = rbuf + 1;
        while (r != p) {
            p--;
            func_002A75A8(p, 2);
        }
        func_002A75A8(h0, 2);
      }
    }
}

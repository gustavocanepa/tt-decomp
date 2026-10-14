/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; void *(*fn)(void *); };
struct VT { char pad[0x130]; VE e130; VE e138; };
struct Ent { int p0; int p4; };
struct Mtx { char pad[0x30]; float x, y, z; char pad2[4]; int idx; };
struct Obj {
    int p0; VT *vt; int p8; int pc; int p10; int p14; int p18;
    float x, y, z;
};
extern "C" {
int func_003F1CA0(Obj *) throw();
int func_003F1E70(Obj *, unsigned short);
Ent *ModelSet2__searchModelName(int, int, int *);
Mtx *func_0041FDA0(int, int);
void ModelSet2___render(int, int, int);
void func_00473050();
void func_004730A8();
void func_004752F8(void *);
void func_00475440(void *);

void func_003F1CA8(Obj *o, int arg1) {
    int n;
    VE *e = &o->vt->e138;
    void *r = e->fn((char *)o + e->adj);
    if (r) {
        func_004752F8(r);
    } else if (func_003F1CA0(o)) {
        int i = 0;
        Ent *p = ModelSet2__searchModelName(func_003F1CA0(o), arg1, &n);
        if (n > 0) {
            do {
                if (func_003F1E70(o, *(unsigned short *)&p->p4))
                    ModelSet2___render(func_003F1CA0(o), p->p4, o->p10);
                i++;
                p++;
            } while (i < n);
        }
    }
    VE *e2 = &o->vt->e130;
    char *base = (char *)e2->fn((char *)o + e2->adj);
    if (base && func_003F1CA0(o)) {
        Mtx *m = func_0041FDA0(func_003F1CA0(o), arg1);
        if (m) {
            func_00473050();
            Mtx *s = (Mtx *)(base + (m->idx << 6));
            func_00475440(m);
            func_004752F8(s);
            if (o->p18 != 1) {
                o->x = s->x;
                o->y = s->y;
                o->z = s->z;
            }
            s->x = s->x - o->x;
            s->y = s->y - o->y;
            s->z = s->z - o->z;
            func_004730A8();
            o->p18 = 1;
        }
    }
}
}

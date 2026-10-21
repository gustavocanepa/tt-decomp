/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Link { Link *a, *b, *c, *d; };
extern "C" Link *func_004A4690(int, int);
inline void *operator new(unsigned int, void *p) { return p; }
struct Cmp { unsigned char v; Cmp() : v(0) {} };
static inline Cmp comparator() { return Cmp(); }
struct Base {
 int alloc; Link *head; int size;
 Base() { head=0; Link *n=func_004A4690(0x10,0x1c); size=0; head=n; }
};
struct Cont : Base {
 Cmp flag; int cnt;
 Cont(const Cmp &v) : Base(), flag(v) {
  head->a=0; head->b=0; head->c=head; head->d=head; cnt=0;
 }
};
struct Cont2 { int alloc; Link *head; Cont2() { Link *n=func_004A4690(0x10,0x14); head=n; n->a=n; head->b=head; } };
struct Src { char pad[0x30]; char *tab; };
struct Rec { char pad[6]; short idx; };
struct Obj { char pad[0x5c]; void *vt; char *p60; int i64, i68; char pad2[0x20]; Cont c1; int pad3; Cont2 c2; };
extern char D_005D9ED8[];
extern "C" void *func_00443F98(Obj *, Src *, Rec *, int, int, int) throw();
extern "C" void func_004469D8(Obj *, int);
extern "C" void func_004467D8(Obj *o, Src *s, Rec *r, int arg, int a4, int a5) {
 func_00443F98(o,s,r,arg,a4,a5);
 o->vt=D_005D9ED8;
 o->p60=s->tab+r->idx*0x24;
 o->i64=0; o->i68=-1;
 int spare[4];
 const Cmp &cmp = comparator();
 new (&o->c1) Cont(cmp);
 new (&o->c2) Cont2;
 func_004469D8(o,arg);
}

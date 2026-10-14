/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { void *p; int pad[3]; };
struct Item { long x; long id; long rest[2]; };
struct G { char pad[16]; Item *items; };
struct It { Item *p; int i; int pad[2]; };
struct Desc { char data[32]; };
extern "C" void func_00128418(H *, int);
extern "C" int func_00131628(void *, const void *, int);
extern "C" void *func_001324D8(void *);
extern "C" void func_00132788(H *);
extern "C" void func_002931B0(H *, H *);
extern "C" void func_002931C8(H *, int);
extern "C" H *func_002944D0(H *, void *, H *);
extern "C" H *func_00295180(H *);
extern "C" void func_002A75A8(H *, int);
extern "C" int func_003FBBA8(Item *);
extern "C" int func_003FBF40(Item *, int);
extern "C" void *func_00408B58(void *);
extern "C" int SPEC_DATABASE__CarEquipments__getDriveTrainType(void *);
extern "C" int func_0040DA58(void *);
extern "C" int func_004107B0(long, Desc *);
extern "C" unsigned char func_00410840(Desc *);
extern "C" unsigned char func_00410850(Desc *);
static inline void init(It *i, Item *p, int n) { i->p=p; i->i=n; }
static inline int eq(const It *a, const It *b) { int r=0; if (a->p == b->p) r=a->i == b->i; return r; }
static inline int neq(const It *a,const It *b) { return eq(a,b)^1; }
static inline long *value(It *a) { Item *e=a->p+a->i; return &e->id; }
static inline void advance(It *a) { a->i=func_003FBF40(a->p,a->i); }
extern "C" H *func_0014F988(H *ret, G *g, int a, int b, int c) {
 H list;
 It end;
 It cur;
 Desc desc;
 H car;
 H tmp;
 Item *p=g->items;
 func_003FBBA8(p);
 func_00295180(&list);
 init(&end,p,1000);
 init(&cur,p,func_003FBF40(p,-1));
 for (; neq(&cur,&end); advance(&cur)) {
  Desc *d=&desc;
  func_004107B0(*value(&cur),d);
  if (a>=0 && a!=func_00410840(d)) continue;
  if (b>=0 && b!=func_00410850(d)) continue;
  H *h=&car;
  func_00132788(h);
  func_00131628(h->p,value(&cur),cur.i);
  if (c>=0 && (!func_0040DA58(func_00408B58(func_001324D8(h->p))) || SPEC_DATABASE__CarEquipments__getDriveTrainType(func_00408B58(func_001324D8(h->p)))!=c)) {
   func_00128418(h,2);
   continue;
  }
  func_002944D0(&tmp,list.p,h);
  func_002A75A8(&tmp,2);
  func_00128418(h,2);
 }
 func_002931B0(ret,&list);
 func_002931C8(&list,2);
 return ret;
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Probe { float a,b,c,d,e,f; int tag; };
struct Obj { char p0[0x14]; float x,y,z; char sub[0x14c]; float px,py,pz; };
extern "C" int func_003CA3F0(void*,int,Probe*,float,float,float);
static inline void init(Probe *p,float z) {
 p->a=z;p->b=z;p->tag=0;p->f=z;p->e=z;p->d=z;p->c=z;
}
extern "C" void func_003C8488(Obj *o,int key) {
 Probe p;
 float *py=&o->py;
 float zero=0.0f;
 init(&p,zero);
 if(func_003CA3F0(o->sub,key,&p,o->px,*py,o->pz)) {
  *py=p.a;o->x=p.c;o->y=p.d;o->z=p.e;
 } else {
  *py=zero;o->x=zero;o->z=zero;o->y=1.0f;
 }
}

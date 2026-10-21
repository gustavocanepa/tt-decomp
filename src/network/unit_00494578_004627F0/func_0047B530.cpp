/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct VEnt {short delta,pad; int (*fn)(void *);};
struct Src {VEnt *vt;};
struct Handle {
 Src *src; int id; u8 *data;
 Handle(Src *,int) throw() __asm__("func_0047AA68");
 void assign(int) throw() __asm__("func_0047AAD0");
 ~Handle() throw() __asm__("func_0047A9B8");
 static void operator delete(void *) __asm__("func_005C1628");
};
struct Obj {Src *src; int id; unsigned idx; unsigned key; u8 done; char text[1];};
extern "C" void *func_004F64C4(void *,const void *,unsigned);
static inline unsigned rd16(const u8 *p) {return p[0] | (p[1]<<8);}
static inline unsigned rd32(const u8 *p) {return p[0] | (p[3]<<24) | ((p[2]<<16) | (p[1]<<8));}
static inline unsigned be32(const u8 *p) {return (p[0]<<24) | (p[1]<<16) | (p[2]<<8) | p[3];}
extern "C" int func_0047B530(Obj *o) {
 if(o->done) return 0;
 Src *s=o->src;
 VEnt *v=s->vt+2;
 int size=v->fn((char *)s+v->delta);
 Handle h(o->src,o->id);
 if(o->text[0]) {
  unsigned n=++o->idx;
  if(n >= ((unsigned)(h.data[2] | (h.data[3]<<8))>>1)) {
   int next=h.data[4] | (h.data[5]<<8) | (h.data[6]<<16) | (h.data[7]<<24);
   if(next<0) {o->done=1;return 0;}
   h.assign(next);
   o->id=next;
   o->idx=0;
  }
 }
 unsigned off=size-o->idx*8;
 unsigned a=off-8;
 unsigned b=off-6;
 u8 *p=h.data+rd16(h.data+a);
 int len=rd16(h.data+b);
 if(be32(p)!=o->key) {o->done=1;return 0;}
 func_004F64C4(o->text,p+4,len-4);
 o->text[len-4]=0;
 return 1;
}

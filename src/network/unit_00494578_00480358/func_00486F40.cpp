/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Holder { u8 *p; int type; u32 fat, start, roots, data, count; };
struct Obj { char *vtbl; };
struct VE1 { short delta,index; u32 (*fn)(void *); };
struct VE5 { short delta,index; int (*fn)(void *,int,void *,u32,int); };
struct Word { u32 v; } __attribute__((packed));
extern "C" u8 *func_004AE750(int,u32);
extern "C" void func_004A45D0(void *) throw();
static inline int half(u8 *p) { return (p[1]<<8)|p[0]; }
static inline u32 word(u8 *p) { return ((Word *)p)->v; }
static inline u32 fallback(u8 *base,int h,int w) { int n=half(base+h); if(n!=0) return n; return word(base+w); }
static inline void reset_info(Obj *io, int sector, u8 *info, u32 size, u32 unknown) {
   Word *q=(Word *)(info+0x1e8);
   Word *r=(Word *)(info+0x1ec);
   u32 freeCount=q->v, nextFree=r->v;
   if(freeCount!=unknown || nextFree!=unknown) {
   q->v=unknown;
   r->v=unknown;
   VE5 *e3=(VE5 *)(io->vtbl+0x18);
   e3->fn((char *)io+e3->delta,sector,info,size,0);
  }
}
extern "C" void func_00486F40(Holder *self, Obj *io, int sector) {
 self->p=0; self->type=0;
 VE1 *e1=(VE1 *)(io->vtbl+0x10);
 u32 size=e1->fn((char *)io+e1->delta);
 u8 *buf=func_004AE750(0x40,size);
 self->p=buf;
 VE5 *e=(VE5 *)(io->vtbl+0x18);
 if(e->fn((char *)io+e->delta,sector,buf,size,1)!=0) return;
 u8 *a=self->p;
 if(half(a+0x1fe)!=0xaa55) return;
 u8 n=a[0xd];
 if(n&(n-1)) return;
 if(size!=half(a+0xb)) return;
 u32 fat=fallback(a,0x16,0x24);
 self->fat=fat;
 u32 start=half(a+0xe)+a[0x10]*fat;
 self->start=start;
 u32 roots=(half(a+0x11)*32+size-1)/size;
 self->roots=roots;
 self->data=start+roots;
 u32 total=fallback(a,0x13,0x20);
 u32 count=(total-self->data)/a[0xd]+2;
 self->count=count;
 if(count<0xff7) self->type=12;
 else if(count<=0xfff6) self->type=16;
 else self->type=32;
 if(self->type==32) {
  u8 *info=func_004AE750(0x40,0x200);
  VE5 *e2=(VE5 *)(io->vtbl+0x18);
  sector+=half(self->p+0x30);
  if(e2->fn((char *)io+e2->delta,sector,info,size,1)==0 && word(info)==0x41615252 && word(info+0x1e4)==0x61417272 && word(info+0x1fc)==0xaa550000) {
   reset_info(io,sector,info,size,0xffffffff);
  }
  func_004A45D0(info);
 }
}

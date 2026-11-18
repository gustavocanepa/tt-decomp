/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32; typedef unsigned char u8;
struct VEntry { short delta,index; int (*fn)(void*); };
struct Source { VEntry *vt; };
struct Handle { Source *mgr; int id; u8 *data; };
extern "C" int func_0047AB68(const u8*,u32,const u8*,u32) throw();
static inline u32 rd16(const u8 *base,int offset) { const u8 *p=base+offset; return p[0] | p[1]<<8; }
static inline int rd32(const u8 *base,int offset) { const u8 *p=base+offset; int a=p[0] | p[3]<<24; int b=p[2]<<16 | p[1]<<8; return a|b; }
static inline int compare(Handle *h,const u8 *key,u32 len,int off) {
 u8 *base=h->data;
 return func_0047AB68(key,len,base+rd16(base,off-8),rd16(base,off-6));
}
extern "C" int func_0047ABF8(Handle *h,const u8 *key,u32 len) {
 u32 count=h->data[2] | h->data[3]<<8;
 Source *o=h->mgr; VEntry *v=o->vt+2;
 int end=v->fn((char*)o+v->delta);
 if(count==1) return rd32(h->data,end-4);
 u32 hi=((count-1)>>1)-1,lo=0;
 if(compare(h,key,len,end)<0) return rd32(h->data,end-4);
 int off=end-hi*8;
 if(compare(h,key,len,off)>0) return rd32(h->data,off-12);
 while(hi-lo>=8) {
  u32 mid=(lo+hi)>>1;
  int at=end-mid*8;
  int r=compare(h,key,len,at);
  if(r==0) return rd32(h->data,at-12);
  if(r<0) hi=mid; else lo=mid;
 }
 if(lo<=hi) {
  off=end-lo*8;
  do {
   int next=off-8;
   int r=compare(h,key,len,off);
   if(r==0) return rd32(h->data,off-12);
   if(r<0) return rd32(h->data,off-4);
   lo++; off=next;
  } while(lo<=hi);
 }
 return -1;
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Report { u8 b[8]; };
struct Result { int x; int flags; int downCount,upCount; int down[16],up[16]; };
struct Obj { char pad[0x14]; int active; char pad18[0x5c]; Report reports[16]; Report previous; int repeat,counter; u8 key; char pad105[3]; int delay,rate,flags; };
extern "C" int func_004CEFA0(Obj*,int,void*,int,int*);
extern "C" void *func_004F6678(void*,int,unsigned);
static inline bool contains(const Report *p,unsigned key) {
 for(unsigned k=2;k<8;k++) if (key==p->b[k]) return true;
 return false;
}
extern "C" Result *func_004C0A70(Result *out,Obj *p) {
 int size;
 Result r;
 func_004F6678(&r,0,sizeof(r));
 if (!p->active) { *out=r; return out; }
 Report *reports=p->reports;
 if (func_004CEFA0(p,0,reports,128,&size)) { *out=r; return out; }
 if ((unsigned)size / 8 >= 16) size=128;
 if (size==0 && p->repeat && p->counter++ > p->delay && p->counter % p->rate == 0) {
  r.down[r.downCount++]=p->key;
  r.flags=p->flags;
  *out=r; return out;
 }
 unsigned j, k, key;
 for (int i=0;i<size/8;i++) {
  Report *rep=&reports[i];
  if (rep->b[7]==1) continue;
  switch(rep->b[0]) {
  case 1:r.flags|=1;break;
  case 16:r.flags|=16;break;
  case 2:r.flags|=2;break;
  case 32:r.flags|=32;break;
  case 4:r.flags|=4;
  case 64:r.flags|=64;break;
  case 8:r.flags|=8;break;
  case 128:r.flags|=128;break;
  }
  p->flags=r.flags;
  for (j=2;j<8;j++) {
   key=p->previous.b[j];
   if (!key) continue;
   for(k=2;k<8;k++) if(key==rep->b[k]) goto next_up;
   r.up[r.upCount++]=key;p->repeat=0;p->previous.b[j]=0;
   next_up:;
  }
  for (j=2;j<8;j++) {
   key=rep->b[j];
   if (!key) continue;
   for(k=2;k<8;k++) if(key==p->previous.b[k]) goto next_down;
   p->repeat=1;p->counter=0;p->key=key;r.down[r.downCount++]=key;
   next_down:;
  }
  p->previous=*rep;
 }
 *out=r; return out;
}

/* compiler: ee-gcc2.96-nsa-nosib */
typedef unsigned char u8;
struct Frame { char data[32]; };
struct Motion { int unk; Frame *frames; int unk8; u8 *code; };
struct Reader { u8 *p; int byte() { int x=*p; p++; return x; } int word() { u8 *q=p; int hi=q[1]; int lo=q[0]; p+=2; return (hi<<8)|lo; } char *str(); } __attribute__((aligned(16)));
struct Entry { short delta, index; void (*fn)(); };
struct Target { int stop; Entry *vt; };
struct Quat { float x,y,z,w; };
extern "C" int func_004A8368(const char *) throw();
inline char *Reader::str() { char *s=(char *)p; p+=func_004A8368(s)+1; return s; }
extern "C" void func_003F4D10(Reader *, Frame *, float *, float, int, unsigned);
extern "C" void func_003F4E08(Reader *, int, int);
extern "C" void func_003F2928(float *, const float *, float, int) throw();
extern "C" void func_00452318(Quat *, float,float,float);
extern "C" void func_004534F0(Quat *, const Quat *, const Quat *, float);
static inline int skip(Target *t, int slot) { Entry *e=t->vt+slot; return ((int (*)(void *))e->fn)((char *)t+e->delta); }
static inline int command(int op, Reader *r, Target *t, Frame *a, Frame *b, float sa, float sb, float blend, int interpolate) {
switch(op) {
case 5: {
 int mask=r->byte();
 if (skip(t,20)) {
 func_003F4E08(r,3,mask); break;
 }
 float v[3]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,3,mask);
 float w[3]; if(interpolate) { func_003F4D10(pc,b,w,sb,3,mask); func_003F2928(v,w,blend,3); }
{ Entry *e=t->vt+5; ((void (*)(void *, float, float, float))e->fn)((char *)t+e->delta, v[0], v[1], v[2]); }
 break;
}
case 6: {
 int mask=r->byte();
 if (skip(t,21)) {
 func_003F4E08(r,1,mask); break;
 }
 float v[1]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,1,mask);
 float w[1]; if(interpolate) { func_003F4D10(pc,b,w,sb,1,mask); func_003F2928(v,w,blend,1); }
{ Entry *e=t->vt+6; ((void (*)(void *, float))e->fn)((char *)t+e->delta, v[0]); }
 break;
}
case 7: {
 int mask=r->byte();
 if (skip(t,22)) {
 func_003F4E08(r,1,mask); break;
 }
 float v[1]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,1,mask);
 float w[1]; if(interpolate) { func_003F4D10(pc,b,w,sb,1,mask); func_003F2928(v,w,blend,1); }
{ Entry *e=t->vt+7; ((void (*)(void *, float))e->fn)((char *)t+e->delta, v[0]); }
 break;
}
case 8: {
 int mask=r->byte();
 if (skip(t,23)) {
 func_003F4E08(r,1,mask); break;
 }
 float v[1]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,1,mask);
 float w[1]; if(interpolate) { func_003F4D10(pc,b,w,sb,1,mask); func_003F2928(v,w,blend,1); }
{ Entry *e=t->vt+8; ((void (*)(void *, float))e->fn)((char *)t+e->delta, v[0]); }
 break;
}
case 9: {
 int mask=r->byte();
 if (skip(t,24)) {
 func_003F4E08(r,3,mask); break;
 }
 float v[3]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,3,mask);
 float w[3]; if(interpolate) { func_003F4D10(pc,b,w,sb,3,mask); func_003F2928(v,w,blend,3); }
{ Entry *e=t->vt+9; ((void (*)(void *, float, float, float))e->fn)((char *)t+e->delta, v[0], v[1], v[2]); }
 break;
}
case 10: {
 int mask=r->byte();
 if (skip(t,25)) {
 func_003F4E08(r,1,mask); break;
 }
 float v[1]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,1,mask);
 float w[1]; if(interpolate) { func_003F4D10(pc,b,w,sb,1,mask); func_003F2928(v,w,blend,1); }
{ Entry *e=t->vt+10; ((void (*)(void *, float))e->fn)((char *)t+e->delta, v[0]); }
 break;
}
case 11: {
 int mask=r->word();
 if (skip(t,26)) {
 func_003F4E08(r,9,mask); break;
 }
 float v[9]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,9,mask);
 float w[9]; if(interpolate) { func_003F4D10(pc,b,w,sb,9,mask); func_003F2928(v,w,blend,9); }
{ Entry *e=t->vt+11; ((void (*)(void *, float, float, float, float, float, float, float, float, float))e->fn)((char *)t+e->delta, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]); }
 break;
}
case 12: {
 int id=r->byte();
 int mask=r->byte();
 if (skip(t,27)) {
 func_003F4E08(r,4,mask); break;
 }
 float v[4]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,4,mask);
 float w[4]; if(interpolate) { func_003F4D10(pc,b,w,sb,4,mask); func_003F2928(v,w,blend,4); }
{ Entry *e=t->vt+12; ((void (*)(void *, int, float, float, float, float))e->fn)((char *)t+e->delta, id, v[0], v[1], v[2], v[3]); }
 break;
}
case 13: {
 int id=r->byte();
 int mask=r->byte();
 if (skip(t,28)) {
 func_003F4E08(r,4,mask); break;
 }
 float v[4]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,4,mask);
 float w[4]; if(interpolate) { func_003F4D10(pc,b,w,sb,4,mask); func_003F2928(v,w,blend,4); }
{ Entry *e=t->vt+13; ((void (*)(void *, int, float, float, float, float))e->fn)((char *)t+e->delta, id, v[0], v[1], v[2], v[3]); }
 break;
}
case 14: {
 int id=r->byte();
 int mask=r->byte();
 if (skip(t,29)) {
 func_003F4E08(r,4,mask); break;
 }
 float v[4]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,4,mask);
 float w[4]; if(interpolate) { func_003F4D10(pc,b,w,sb,4,mask); func_003F2928(v,w,blend,4); }
{ Entry *e=t->vt+14; ((void (*)(void *, int, float, float, float, float))e->fn)((char *)t+e->delta, id, v[0], v[1], v[2], v[3]); }
 break;
}
case 15: {
 int id=r->byte();
 int mask=r->byte();
 if (skip(t,30)) {
 func_003F4E08(r,3,mask); break;
 }
 float v[3]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,3,mask);
 float w[3]; if(interpolate) { func_003F4D10(pc,b,w,sb,3,mask); func_003F2928(v,w,blend,3); }
{ Entry *e=t->vt+15; ((void (*)(void *, int, float, float, float))e->fn)((char *)t+e->delta, id, v[0], v[1], v[2]); }
 break;
}
case 16: {
 int mask=r->byte();
 char *name=r->str();
 if (skip(t,31)) {
 func_003F4E08(r,1,mask); break;
 }
 float v[1]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,1,mask);
 float w[1]; if(interpolate) { func_003F4D10(pc,b,w,sb,1,mask); func_003F2928(v,w,blend,1); }
{ Entry *e=t->vt+16; ((void (*)(void *, char *, float))e->fn)((char *)t+e->delta, name, v[0]); }
 break;
}
case 17: {
 int mask=r->byte();
 char *name=r->str();
 if (skip(t,32)) {
 r->str();
 func_003F4E08(r,2,mask); break;
 }
 float v[2]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,2,mask);
 float w[2]; if(interpolate) { func_003F4D10(pc,b,w,sb,2,mask); func_003F2928(v,w,blend,2); }
{ Entry *e=t->vt+17; ((void (*)(void *, char *, float, float))e->fn)((char *)t+e->delta, name, v[0], v[1]); }
 break;
}
case 18: {
 int mask=r->byte();
 char *name=r->str();
 if (skip(t,33)) {
 r->str();
 func_003F4E08(r,3,mask); break;
 }
 float v[3]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,3,mask);
 float w[3]; if(interpolate) { func_003F4D10(pc,b,w,sb,3,mask); func_003F2928(v,w,blend,3); }
{ Entry *e=t->vt+18; ((void (*)(void *, char *, float, float, float))e->fn)((char *)t+e->delta, name, v[0], v[1], v[2]); }
 break;
}
case 19: {
 int mask=r->byte();
 if (skip(t,34)) {
 func_003F4E08(r,3,mask); break;
 }
 float v[3]; Reader copy; Reader *pc=&copy; pc->p=r->p;
 func_003F4D10(r,a,v,sa,3,mask);
 Quat q; Quat *pq=&q; func_00452318(pq,v[0],v[1],v[2]);
 float w[3]; if(interpolate) { func_003F4D10(pc,b,w,sb,3,mask); Quat z; Quat *pz=&z; Quat out; Quat *po=&out; func_00452318(pz,w[0],w[1],w[2]); func_004534F0(po,pq,pz,blend); pq->x=po->x; pq->y=po->y; pq->z=po->z; pq->w=po->w; }
{ Entry *e=t->vt+19; ((void (*)(void *, float, float, float, float))e->fn)((char *)t+e->delta, pq->x, pq->y, pq->z, pq->w); }
 break;
}
default: return 0;
}
return 1;
}
extern "C" int func_003F2AE0(Motion *m, int ia, float sa, int ib, float sb, float blend, Target *t) {
 Reader r; Reader *pr=&r; pr->p=m->code;
 Frame *a=&m->frames[ia], *b=&m->frames[ib];
 int more=1;
 Frame *first=blend<1.0f?a:b;
 float scale=blend<1.0f?sa:sb;
 int interpolate=0; if(blend>0.0f && blend<1.0f) interpolate=1;
 do {
  int op=pr->byte();
  switch(op) {
   case 0: break;
   case 1: more=0; { Entry *e=t->vt+2; ((void (*)(void *))e->fn)((char *)t+e->delta); } break;
   case 2: { Entry *e=t->vt+3; ((void (*)(void *))e->fn)((char *)t+e->delta); } break;
   case 3: { Entry *e=t->vt+4; ((void (*)(void *))e->fn)((char *)t+e->delta); } break;
   case 4: { char *name=pr->str(); { Entry *e=t->vt+1; ((void (*)(void *, char *))e->fn)((char *)t+e->delta, name); } break; }
   default: if(!command(op,pr,t,first,b,scale,sb,blend,interpolate)) return 0;
  }
  if(t->stop) more=0;
 } while(more);
 return 1;
}

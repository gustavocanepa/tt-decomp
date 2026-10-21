/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Packet {u8 a,b; signed char c,count; short d; u8 pad,e; short f,g,h,i; u8 data[16];};
struct Obj {unsigned start,end; char pad[0x18-8]; Packet prev; int done,written,frame,repeat; void *header; unsigned size;};
extern "C" void AutomobileControlRecord__Recorder__steer_update(Obj *) throw();
extern "C" void AutomobileControlRecord__Recorder__write_count(Obj *,int) throw();
extern "C" void AutomobileControlRecord__Recorder__finish(Obj *);
extern "C" void func_00552540(Obj *,u8 *,u8 *);
extern "C" void func_00552588(Obj *,signed char *,signed char *);
extern "C" void func_005525D0(Obj *,short *,short *);
extern "C" void AutomobileControlRecord__Recorder__write(Obj *o,Packet *n) {
 if(!o->done) {
  int mask=0;
  AutomobileControlRecord__Recorder__steer_update(o);
  o->written=1;
  if(o->prev.a!=n->a) mask|=0x100;
  if(o->prev.b!=n->b) mask|=0x80;
  if(o->prev.c!=n->c) mask|=0x10;
  if(o->prev.d!=n->d) mask|=2;
  if(o->prev.e!=n->e) mask|=1;
  if(o->prev.f!=n->f) mask|=4;
  if(o->prev.g!=n->g) mask|=8;
  if(o->prev.h!=n->h) mask|=0x40;
  if(o->prev.i!=n->i) mask|=0x20;
  if(o->prev.count!=n->count) mask|=0x200;
  else {
   for(int i=0;i<n->count;i++) {
    if(o->prev.data[i]!=n->data[i]) {mask|=0x200; break;}
   }
  }
  if(++o->frame==1 || mask) {
   if(o->repeat) AutomobileControlRecord__Recorder__write_count(o,o->repeat);
   AutomobileControlRecord__Recorder__write_count(o,mask+1);
   if(mask&0x100) func_00552540(o,&o->prev.a,&n->a);
   if(mask&0x80) func_00552540(o,&o->prev.b,&n->b);
   if(mask&0x10) func_00552588(o,&o->prev.c,&n->c);
   if(mask&2) func_005525D0(o,&o->prev.d,&n->d);
   if(mask&1) func_00552540(o,&o->prev.e,&n->e);
   if(mask&4) func_005525D0(o,&o->prev.f,&n->f);
   if(mask&8) func_005525D0(o,&o->prev.g,&n->g);
   if(mask&0x40) func_005525D0(o,&o->prev.h,&n->h);
   if(mask&0x20) func_005525D0(o,&o->prev.i,&n->i);
   if(mask&0x200) {
    int count=n->count;
    AutomobileControlRecord__Recorder__write_count(o,count+1);
    for(int i=0;i<count;i++) func_00552540(o,&o->prev.data[i],&n->data[i]);
   }
   if(o->end-o->start+0x40>=o->size) AutomobileControlRecord__Recorder__finish(o);
   o->repeat=0;
  }
  o->repeat++;
 }
 o->prev=*n;
}

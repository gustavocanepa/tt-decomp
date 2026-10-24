/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[8]; char *vt; };
struct Self { char pad[0x4840]; Obj *obj; };
struct E1 { short delta,index; int (*fn)(void *); };
struct E2 { short delta,index; void (*fn)(void *,int,int); };
extern "C" int func_0037B4C0(void *);
static inline int check(Obj *o) {
 E1 *e = (E1 *)(o->vt+0x198);
 return e->fn((char *)o+e->delta);
}
static inline void send(Obj *o,int a,int b) {
 E2 *e = (E2 *)(o->vt+0x1A0);
 e->fn((char *)o+e->delta,a,b);
}
extern "C" int func_0036BD90(Self *self,int arg) {
 int r=func_0037B4C0((char *)self+0x4850);
 if (r != 0) {
  if(check(self->obj)) {
   if(arg) send(self->obj,0,arg);
   return r;
  }
 }
 return 0;
}

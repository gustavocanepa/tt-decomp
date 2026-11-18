/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int size; char pad[0x48]; char *vtbl; };
struct VE3 { short delta,index; void (*fn)(void *,int *,int *,int); };
struct VE0 { short delta,index; int (*fn)(void *); };
struct VE1 { short delta,index; int (*fn)(void *,int); };
extern "C" void func_0019B4B8(Obj *) throw();
extern "C" void func_0019B8F8(Obj *,int) throw();
extern "C" void func_0019B920(Obj *,int) throw();
extern "C" void func_0019BDE8(Obj *self,int arg) {
 func_0019B4B8(self);
 int x=0,y=0;
 VE3 *e=(VE3 *)(self->vtbl+0xF0);
 e->fn((char *)self+e->delta,&x,&y,arg);
 x++; y++;
 VE0 *e0=(VE0 *)(self->vtbl+0xF8);
 x+=e0->fn((char *)self+e0->delta);
 VE1 *e1=(VE1 *)(self->vtbl+0x100);
 y+=e1->fn((char *)self+e1->delta,arg);
 y+=(x+1)/2+1;
 self->size=y;
 func_0019B8F8(self,1);
 func_0019B920(self,1);
}

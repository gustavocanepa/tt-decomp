/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int a,state; char data[0x60]; int n; };
extern "C" void func_002E8590(void *,int *) throw();
extern "C" void func_002E88B0(Obj *,int) throw();
extern "C" void func_002E8EE0(Obj *,int *);
extern "C" void AutomobileControlRecord__Manager__save(Obj *self,int *out) {
 int pos=*out;
 *out=pos+4;
 int *header=(int *)((char *)out+pos);
 switch(self->state) {
 case 0:
  *header=0;
  return func_002E8590(self->data,out);
 case 1:
  *header=self->n;
  for(int i=0;i<self->n;i++) {
   func_002E88B0(self,i);
   func_002E8EE0(self,out);
  }
  return;
 case 2:
  *header=1;
  return func_002E8EE0(self,out);
 }
}

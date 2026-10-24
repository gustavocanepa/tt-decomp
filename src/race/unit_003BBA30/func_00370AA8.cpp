/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int active,calls,dropped,count,total; int data[1000]; };
extern "C" void *func_004F6574(void *,const void *,unsigned int) throw();
extern "C" void func_00370AA8(Obj *o,int x) {
 o->calls++;
 if(o->active==0) {
 o->total+=x;
 if(o->count==1000) {
 o->dropped++;
 func_004F6574(o->data,o->data+1,0xf9c);
 o->count--;
 }
 o->data[o->count++]=x;
 }
}

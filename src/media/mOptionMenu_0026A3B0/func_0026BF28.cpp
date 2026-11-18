/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad[0xE0]; void *c4; char pad2[0x34]; int fc; };
extern "C" void func_0026BA40(S *,int) throw();
extern "C" void func_0026BD80(S *,int,int) throw();
extern "C" int func_0026BF28(S *self,int arg1) {
 if (self->c4) {
  if (self->fc==0) { func_0026BA40(self,arg1); return 2; }
  else { func_0026BD80(self,arg1,0); return 2; }
 }
 return 2;
}

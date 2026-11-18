/* compiler: ee-gcc2.96-nogcse */
struct Reader { int pos, v4, limit; };
struct S { char pad[0xE0]; Reader reader; char pad2[0x28]; char *flags; };
extern "C" int func_004AC650(Reader *,int);
extern "C" void func_004AC580(Reader *,int);
extern "C" int func_0027E010(S *) throw();
extern "C" int func_0027E108(S *self,int arg1) {
 Reader *r = &self->reader;
 int old = r->pos;
 int result = func_004AC650(r,-arg1);
 char *flags = self->flags;
 if (flags) {
  int i = r->pos;
  while (flags[i]) {
   --i;
   if (i < r->v4) { func_004AC580(r, old); return 0; }
  }
  func_004AC580(r, i);
 }
 func_0027E010(self);
 return result;
}

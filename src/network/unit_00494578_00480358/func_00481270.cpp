/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0xA8]; const char *a8; int ac; int b0; const char *b4; };
extern "C" void func_004811D0(void*,unsigned char*) throw();
extern "C" unsigned func_004A8368(const char*) throw();
extern "C" void func_004BEAF0(int,int,int,unsigned char*);
extern "C" void func_00481270(Self *s,int unused,int a,int b) {
 unsigned char *p=0;
 if(s->b0==0) {
  a<<=11;
  unsigned n=func_004A8368(s->a8);
  n+=func_004A8368(s->b4);
  p=(unsigned char*)__builtin_alloca(n+2);
  func_004811D0(s,p);
 }
 func_004BEAF0(a,b,0x8000,p);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_002BFCC0(void *);
extern "C" void func_002BC0E0(void *, int);
extern "C" void func_004A48D8(void *, int);
extern "C" void func_0050E1A8(void *) throw();
struct E { int a,b,c; };
extern "C" void func_002BFC10(void *arg0,int flags) {
 func_002BFCC0(arg0);
 if ((char *)arg0 != (char *)-0x8) {
  E *p = (E *)((char *)arg0 + 0x6008);
  E *begin = (E *)((char *)arg0 + 0x8);
  while (begin != p) {
   --p;
   func_002BC0E0(&p->c,2);
  }
 }
 func_004A48D8(arg0,2);
 if (flags & 1) return func_0050E1A8(arg0);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0057C5D0;
extern "C" void func_002BC270(void *);
extern "C" int func_002BFCC0(void *);
extern "C" void func_004A48C0(void *);
struct E { int a,b,c; };
extern "C" int func_002BFB90(void *arg0) {
 E *p = (E *)((char *)arg0 + 0x8);
 int n = 0x7ff;
 func_004A48C0(arg0);
 do {
  p->a = 0;
  void *h = &p->c;
  --n;
  p->b = D_0057C5D0;
  ++p;
  func_002BC270(h);
 } while (n != -1);
 return func_002BFCC0(arg0);
}

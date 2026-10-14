/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Root { char pad[0x64]; virtual ~Root(); };
struct Base : Root { int x68; Base() __asm__("func_00100928"); virtual ~Base(); };
struct CarIconMaker : Base {
 int a; void *b; void *const c; int x78; int x7c;
 CarIconMaker(int,void *,void *) __asm__("func_00389420");
 virtual ~CarIconMaker();
};
CarIconMaker::CarIconMaker(int a0,void *b0,void *c0) : a(a0), b(b0), c(c0) { x7c=0; }

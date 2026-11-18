/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Range { int x; short begin,end; };
extern "C" Range *func_004834E8(void *);
extern "C" void func_00482178(void *, Range *, u16 *, int) throw();
extern "C" void func_00483628(void *, Range *, u16 *, int);
extern "C" int func_004868A8(u16 *, int);
extern "C" int func_00486C98(const u16 *);
static inline int length(const u16 *s) { int i=0; while (s[i]) i++; return i; }
extern "C" void func_00482748(void *p) {
 u16 buf[256];
 u16 out[8];
 Range *r=func_004834E8(p);
 if (r->end-r->begin>0) {
 func_00482178(p,r,buf,256);
 int i=length(buf);
 if (func_004868A8(out,func_00486C98(buf+i-1))) func_00483628(p,r,out,1);
 }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Comparator { char *vt; void *fn; };
extern char D_005A63D8[],D_005A63B8[],D_005A65B0[];
extern "C" int func_002958F0(void *,Comparator *);
extern "C" int func_002931C8(void *,int);
extern "C" void hArrayCompare__structor_0(void **array,void *fn,int descending) {
 Comparator c;
 if(descending) {
  void *p=*array;
  c.vt=D_005A63D8; c.fn=fn;
  char *base=D_005A65B0;
  func_002958F0(p,&c);
  c.vt=base;
 } else {
  void *p=*array;
  c.vt=D_005A63B8; c.fn=fn;
  char *base=D_005A65B0;
  func_002958F0(p,&c);
  c.vt=base;
 }
 func_002931C8(array,2);
}

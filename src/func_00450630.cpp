/* compiler: ee-gcc2.96-no-strict-aliasing */
struct M { float a[16]; };
static inline int less(int i, int n) { return i<n; }
extern "C" int func_00450630(M *a, M *b) {
 int i=0;
 do {
  int off=i*4;
  ++i;
  if(*(float *)((char *)a+off) != *(float *)((char *)b+off)) return 0;
 } while(less(i,16));
 return 1;
}

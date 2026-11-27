/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
static inline int len(const u16 *p) {
 int n=0;
 if (*p) { const u16 *q=p; do { ++q; ++n; } while (*q); }
 return n;
}
extern "C" int func_00481DE8(u16 *dst,int cap,int pos,int remove,const u16 *src) {
 int n=len(src);
 int diff=n-remove;
 if (pos+diff+1>=cap) return pos;
 int size=len(dst);
 if(size+diff+1>=cap) return pos;
 if(pos==size) {
  for(int i=0;i<n;i++) dst[pos+i]=src[i];
  dst[size+n]=0;
  return pos+n;
 }
 if(diff) {
  for(int i=0;i<size-(pos+remove);i++) {
   if(diff>0) dst[size+diff-i-1]=dst[size-i-1];
   else dst[pos+n+i]=dst[pos+n-diff+i];
  }
 }
 int end=size+diff;
 for(int i=0;i<n;i++) dst[pos+i]=src[i];
 dst[end]=0;
 return pos+n;
}

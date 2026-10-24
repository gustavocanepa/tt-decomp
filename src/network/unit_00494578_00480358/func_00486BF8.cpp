/* compiler: ee-gcc2.96-nogcse */
extern "C" int func_00486BA8(short *, int) throw();
extern "C" void func_00486BF8(short *dst, int max, const unsigned short *src) {
 int len=0;
 if (*src) {
  const unsigned short *scan=src;
  do { scan++; len++; } while(*scan);
 }
 int limit=max-1;
 int count = limit<len ? limit : len;
 if (count>0) {
  const unsigned short *p=src;
  int n=count;
  do {
   len=*p;
   p++;
   n--;
   if (func_00486BA8(dst,len)) dst++;
  } while(n);
 }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004A8368(const char *) throw();
extern "C" char *func_001F2F30(char *s) {
 int n=func_004A8368(s);
 int i=0;
 char *p;
 if(n>0) {
 int c=*s;
 p=s;
 if(c==32) {
 do {
 ++i;
 p=s+i;
 if(i>=n) break;
 } while(*p==32);
 }
 } else p=s;
 return p;
}

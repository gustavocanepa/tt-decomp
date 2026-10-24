/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x004e5700.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern "C" int func_004E5700(const unsigned char *a,const unsigned char *b,int n) {
 goto test;
 loop: {
   int x=*a++;
   int y=*b++;
   if(x!=y) return x-y;
   if(x==0) return 0;
 }
 test:
 switch(n--) {
 case 0: return 0;
 default: goto loop;
 }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001A3C50(short *out, short *outEnd, const short *in, const short *inEnd, int mask) {
 int index = 0;
 while (in < inEnd && out < outEnd) {
  int n = *in++;
  if (n > 0) {
   short value = *in++ | -32768;
   for (int i = 0; i < n; i++) {
    if ((index++ & mask) == 0) {
     *out++ = value;
     if (out >= outEnd) return;
    }
   }
  } else if (n < 0) {
   n = -n;
   for (int i = 0; i < n; i++) {
    if ((index++ & mask) == 0) *out++ = *in | -32768;
    in++;
    if (out >= outEnd || in >= inEnd) return;
   }
  }
 }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0038FAA0(char *, int, unsigned int);
extern "C" void func_0038FA50(char *buf, int unused, int n, int sign) {
 unsigned int magnitude = -(unsigned int)n;
 if (n >= 0) magnitude = n;
 char *out = buf;
 if (sign) {
  out++;
  if (n >= 0) *buf = 0x2B;
  else *buf = 0x7F;
 }
 func_0038FAA0(out, unused, magnitude);
}

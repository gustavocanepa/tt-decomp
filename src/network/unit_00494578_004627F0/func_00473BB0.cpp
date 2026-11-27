/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00473BB0(float x) {
 float v=64.0f;
 int bits=0;
 int top=0;
 int i=10;
 do {
  bits <<= 1;
  if (v<=x) {
   x-=v;
   bits|=1;
   top=top<i ? i:top;
  }
  i--;
  v*=0.5f;
 } while(i>=0);
 int low=bits&15;
 bits >>= 4;
 int rev=0;
 i=0;
 do {
  int bit=(low>>i)&1;
  i++;
  rev=(rev<<1);
  rev |= bit;
 } while(i<4);
 bits |= rev << 6;
 return bits | (top << 16);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_003292D0(float a, float b) {
 unsigned int r=0;
 if (b<0.0f) {
  if (a>0.0f) r=1;
 } else if (b>0.0f) {
  if (a<0.0f) r=1;
 } else {
  if (b==0.0f) r=1;
 }
 return (float)r;
}

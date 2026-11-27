/* compiler: ee-gcc2.96-no-strict-aliasing */

extern void func_004751E0(float angle);
inline static float bits_to_float(unsigned long long b)
{
  float f;
  asm("mtc1 %1, %0" : "=f"(f) : "r"(b));
  return f;
}

extern float func_00473D10(float *s, float *c, float angle)
{
  unsigned short new_var;
  float new_var2;
  unsigned long long sc;
  float *new_var3;
  func_004751E0(angle);
  new_var2 = 32;
  asm volatile("qmfc2.i %0, $vf1" : "=r"(sc));
  new_var = new_var2;
  float sine = bits_to_float(sc);
  sc >>= new_var;
  new_var3 = s;
  new_var2 = bits_to_float(sc);
  *new_var3 = sine;
  *c = new_var2;
  return sine;
}

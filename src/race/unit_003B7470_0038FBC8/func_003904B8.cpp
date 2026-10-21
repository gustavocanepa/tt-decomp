
extern float func_003904B8(int unused, float *a1, float *a2, float x)
{
  float zero = 0.0f;
  float r;
  float t;
  float ax;
  float ay;
  float az;
  float bx;
  float by;
  float bz;
  float xx;
  float yy;
  float zz;
  float p0;
  float p1;
  float p2;
  float len2;
  float dot;
  int n;
  int i;
  if (x < zero)
  {
    return 1.0f;
  }
  n = (int) (x + 0.5f);
  if (n == 0)
  {
    return 1.0f;
  }
  if (n > 32)
  {
    n = 32;
  }
  ax = a1[0];
  ay = a1[1];
  bx = a2[0];
  xx = ax * ax;
  yy = ay * ay;
  p0 = bx * ax;
  by = a2[1];
  bz = a2[2];
  p1 = by * ay;
  az = a1[2];
  zz = az * az;
  p2 = bz * az;
  len2 = xx + yy;
  dot = p0 + p1;
  len2 = len2 + zz;
  dot = dot + p2;
  asm("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(dot), "f"(len2));
  t = r;
  if (r < zero)
  {
    return -1.0f;
  }
  for (i = 0; i < (n - 1); i++)
  {
    r = r * t;
  }

  return r;
}

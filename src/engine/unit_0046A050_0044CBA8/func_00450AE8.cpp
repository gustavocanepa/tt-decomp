#include "types.h"

extern "C" void func_00450AE8(f32 *out, const f32 *m, const f32 *v)
{
  int k3 = 12;
  int k = 4;
  int k2 = 8;
  const f32 *v3 = (const f32 *) (((const char *) v) + k3);
  const f32 *m3 = (const f32 *) (((const char *) m) + k3);
  const f32 *v1 = (const f32 *) (((const char *) v) + k);
  const f32 *m2 = (const f32 *) (((const char *) m) + k2);
  const f32 *m1 = (const f32 *) (((const char *) m) + k);
  const f32 *v2 = (const f32 *) (((const char *) v) + k2);
  f32 *o2 = (f32 *) (((char *) out) + k2);
  f32 *o1 = (f32 *) (((char *) out) + k);
  f32 *o3 = (f32 *) (((char *) out) + k3);

  out[0] = ((v3[0] * m[0] + m3[0] * v[0]) - v1[0] * m2[0]) + m1[0] * v2[0];
  o1[0] = ((v3[0] * m1[0] + m3[0] * v1[0]) + v[0] * m2[0]) - m[0] * v2[0];
  o2[0] = ((m[0] * v1[0] - v[0] * m1[0]) + v3[0] * m2[0]) + m3[0] * v2[0];
  o3[0] = ((m3[0] * v3[0] - m[0] * v[0]) - m1[0] * v1[0]) - m2[0] * v2[0];
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

extern "C" void func_00450CB8(const f32 *m, f32 *out, const f32 *v)
{
  int k = 4;
  int k2 = 8;
  const f32 *v1 = (const f32 *) (((const char *) v) + k);
  const f32 *v2 = (const f32 *) (((const char *) v) + k2);
  f32 *o1 = (f32 *) (((char *) out) + k);
  f32 *o2 = (f32 *) (((char *) out) + k2);

  f32 m00 = m[0] * m[0];
  f32 m01 = m[0] * m[1];
  f32 m02 = m[0] * m[2];
  f32 m03 = m[0] * m[3];
  f32 m11 = m[1] * m[1];
  f32 m12 = m[1] * m[2];
  f32 m13 = m[1] * m[3];
  f32 m22 = m[2] * m[2];
  f32 m23 = m[2] * m[3];

  out[0] = 2.0f * ((((0.5f - m11) - m22) * v[0]) + ((m01 - m23) * v1[0]) + ((m02 + m13) * v2[0]));
  o1[0] = 2.0f * (((m01 + m23) * v[0]) + (((0.5f - m22) - m00) * v1[0]) + ((m12 - m03) * v2[0]));

  f32 t3 = (m02 - m13) * v[0];
  f32 vb = v1[0];
  f32 t6 = (m12 + m03) * vb;
  o2[0] = 2.0f * ((t3 + t6) + (((0.5f - m00) - m11) * v2[0]));
}

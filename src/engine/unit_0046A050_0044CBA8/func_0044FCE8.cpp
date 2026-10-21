typedef float f32;

inline const f32 inline_fn(const f32 *arg0)
{
  return arg0[0];
}

extern "C" void func_0044FCE8(f32 *out, const f32 *m, const f32 *v)
{
  int k = 4;
  int k2 = 8;
  f32 *o1 = (f32 *) (((char *) out) + k);
  f32 *o2 = (f32 *) (((char *) out) + k2);
  const f32 *v2 = (const f32 *) (((const char *) v) + k2);
  const f32 *v1 = (const f32 *) (((const char *) v) + k);
  out[0] = ((inline_fn(m) * inline_fn(v)) + (m[4] * inline_fn(v1))) + (m[8] * inline_fn(v2)) + m[12];
  o1[0] = ((m[1] * inline_fn(v)) + (m[5] * inline_fn(v1))) + (m[9] * inline_fn(v2)) + m[13];
  o2[0] = ((m[2] * inline_fn(v)) + (m[6] * inline_fn(v1))) + (m[10] * inline_fn(v2)) + m[14];
}

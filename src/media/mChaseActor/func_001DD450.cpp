
typedef int s32;
typedef float f32;
extern f32 func_001DD408(void *);
extern void *func_004AFF28(void *, f32, f32);
extern f32 func_001DD450(char *arg0)
{
  f32 v;
  char *s1;
  s1 = arg0 + 0x20;
  v = func_001DD408(arg0);
  if ((*((f32 *) (arg0 + 0x2C))) != v)
  {
    *((f32 *) (arg0 + 0x2C)) = v;
  }
  else
  {
    v = v + 0x1.0624DCp-10f;
  }
  if (v > 1.0f)
  {
    v = 1.0f;
  }
  if (v < 1.0f)
  {
    s1 = arg0;
    s1 = s1 + 0x20;
    func_004AFF28(s1, v, 0x1.47AE14p-7f);
  }
  else
  {
    func_004AFF28(s1, v, 0x1.333332p-2f);
  }
  return *((f32 *) (s1 + 0x8));
}

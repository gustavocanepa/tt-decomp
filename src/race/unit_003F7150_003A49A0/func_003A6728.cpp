
typedef int s32;
typedef float f32;
void func_003A6728(char *arg0)
{
  char *v1;
  f32 *a2;
  s32 i;
  s32 j;
  s32 off;
  for (i = 0, off = 0; i < 4; i++, off += 4)
  {
    v1 = arg0 + off;
    a2 = (f32 *) (v1 + (i * 16));
    for (j = 0; j < 4; j++)
    {
      if (!(i != j))
      {
        *a2 = 1.0f;
      }
      else
      {
        *((s32 *) v1) = 0;
      }
      v1 = v1 + 16;
    }

  }

  *((f32 *) (arg0 + 0x44)) = 0x1.9999980000000p-4f;
  *((f32 *) (arg0 + 0x48)) = 750.0f;
  *((f32 *) (arg0 + 0x40)) = (*((f32 *) (arg0 + 0x4C)) = 1.0f);
  *((s32 *) (arg0 + 0x50)) = 0;
}

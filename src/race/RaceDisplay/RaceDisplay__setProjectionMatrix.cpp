
typedef float f32;
typedef int s32;
struct func_00350AD8_mtx
{
  f32 m0;
  s32 z4;
  s32 z8;
  s32 zC;
  s32 z10;
  f32 m14;
  s32 z18;
  s32 z1C;
  s32 z20;
  s32 z24;
  f32 m28;
  s32 z2C;
  f32 m30;
  f32 m34;
  s32 z38;
  f32 m3C;
};
extern void RaceDisplay__setProjectionMatrix(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3)
{
  struct func_00350AD8_mtx *t = (struct func_00350AD8_mtx *) (arg0 + 0x70);
  t->m28 = -0x1.0p+0f;
  t->z4 = 0;
  t->z8 = 0;
  t->zC = 0;
  t->z10 = 0;
  t->z18 = 0;
  t->z1C = 0;
  t->z20 = 0;
  t->z24 = 0;
  t->m0 = (f32) (0x1.0p+1f / (fparg1 - fparg0));
  t->z2C = 0;
  t->z38 = 0;
  t->m14 = (f32) (0x1.0p+1f / (fparg3 - fparg2));
  t->m30 = (f32) ((fparg0 + fparg1) / (fparg0 - fparg1));
  t->m34 = (f32) ((fparg2 + fparg3) / (fparg2 - fparg3));
  t->m3C = 0x1.0p+0f;
}

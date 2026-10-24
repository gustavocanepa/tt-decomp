
typedef int s32;
typedef unsigned int u32;
extern void func_0033E078(void *self, void *val);
extern void RaceTrainingBase__initialize(void *b, s32 x);
extern void func_0037E020(void *arg0, s32 arg1);
extern void RaceDisplay__virtual_06(void *arg0, s32 arg1);
inline static void reset_call(void *s)
{
  func_0033E078(s, 0);
}

extern void func_00374068(void *arg0, s32 arg1)
{
  char *self = (char *) arg0;
  void *new_var;
  char *t0;
  char *t2;
  t0 = self + 0x37E40;
  t2 = self + 0xE500;
  reset_call(arg0);
  new_var = arg0;
  RaceTrainingBase__initialize(new_var, arg1);
  if (((u32) ((*((s32 *) (self + 0xD8C))) - 2)) < 2U)
  {
    reset_call(arg0);
  }
  else
  {
    func_0033E078(arg0, t0);
    func_0037E020(t0, (s32) (self + 0x37E10));
  }
  RaceDisplay__virtual_06(t2, 1);
  *((s32 *) (t2 + 8)) = (s32) (self + 0x37E10);
}


typedef int s32;
struct Obj003BB958
{
  char pad0[4];
};
struct Sub003C0CC8
{
  char pad0[8];
  s32 *tbl;
};
struct Ctx003C0CC8
{
  char pad0[0x60];
  struct Sub003C0CC8 *sub;
};
extern s32 func_0036BC28(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003708F0(struct Obj003BB958 *dst, const struct Obj003BB958 *src);
extern s32 func_00370980(struct Obj003BB958 *arg0, struct Obj003BB958 *arg1);
inline int inline_fn(s32 arg0)
{
  return arg0 != 0;
}

extern s32 func_003767E8(struct Ctx003C0CC8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  struct Sub003C0CC8 *sub;
  struct Obj003BB958 *temp_s0;
  s32 temp_a0;
  s32 temp_s1;
  s32 temp_s3;
  sub = arg0->sub;
  temp_s0 = (struct Obj003BB958 *) (((char *) arg0) + 0x928);
  temp_a0 = *((s32 *) (((char *) sub->tbl) + (arg1 * 4)));
  func_0036BC28(temp_a0, arg2, 1);
  temp_s1 = temp_a0 + 0x1264;
  temp_s3 = func_00370980((struct Obj003BB958 *) temp_s1, temp_s0);
  if (inline_fn(arg3))
  {
    func_003708F0(temp_s0, (const struct Obj003BB958 *) temp_s1);
  }
  return temp_s3;
}

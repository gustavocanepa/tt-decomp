
typedef int s32;
typedef unsigned char u8;
struct Buf005C6F48
{
  u8 b0;
  char pad1[3];
  s32 w4;
  u8 b8;
};
extern void func_005154B8(s32, s32);
extern void func_00515658(s32, s32, s32, u8);
void func_00512D18(s32 arg0, s32 arg1, u8 arg2)
{
  struct Buf005C6F48 buf;
  s32 v0 = arg0;
  s32 s0;
  s32 diff = (arg1 - v0) >> 3;
  buf.b0 = arg2;
  if (diff >= 0x11)
  {
    u8 r;
    func_005154B8(arg0, v0 + 0x80);
    r = buf.b0;
    buf.w4 = v0 + 0x80;
    buf.b8 = r;
    func_00515658(v0 + 0x80, arg1, 0, r);
  }
  else
  {
    func_005154B8(arg0, arg1);
  }
}

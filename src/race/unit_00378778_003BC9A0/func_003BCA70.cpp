typedef int s32;
typedef float f32;

struct Obj;
struct func_002FEE80_Obj;

extern "C" f32 func_002FEE80(func_002FEE80_Obj *self, int k);
extern "C" f32 func_003BC9A0(Obj *arg0, s32 arg1);
extern "C" void *func_004172F0(void);
extern "C" f32 func_00417DC8(Obj *arg0);

extern "C" f32 func_003BCA70(Obj *arg0, s32 arg1)
{
  f32 var_f20;
  f32 temp;
  f32 r;
  f32 hi;
  f32 lo;

  if (arg1 == 0)
  {
    var_f20 = -func_002FEE80((func_002FEE80_Obj *) arg0, 9) * 0x1.999998p-2f;
    r = func_003BC9A0(arg0, 0);
    hi = 0x1.921FB4p+0f;
    lo = -0x1.921FB4p+0f;
    if (r < lo)
    {
      var_f20 = 0.0f;
    }
    else if (hi < r)
    {
      var_f20 = 0.0f;
    }
    return var_f20;
  }

  var_f20 = 0x1.999998p-2f;
  if (func_004172F0() != 0)
  {
    var_f20 = func_00417DC8((Obj *) func_004172F0());
  }
  temp = -func_002FEE80((func_002FEE80_Obj *) arg0, 9);
  return temp * var_f20;
}

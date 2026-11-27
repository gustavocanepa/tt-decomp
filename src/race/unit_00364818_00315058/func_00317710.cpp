
typedef float f32;
f32 func_00317710(f32 fparg0)
{
  f32 var_f0;
  f32 var_f1;
  ;
  if (fparg0 <= 0x1.0p+1f)
  {
    return 0x1.0p+4f;
  }
  if (fparg0 < 0x1.ep+3f)
  {
    var_f0 = (((0x1.ep+3f - fparg0) * 0x1.8p+3f) / 0x1.ap+3f) + 0x1.0p+2f;
    if (var_f0 <= 0x1.0p+2f)
    {
      var_f0 = 0x1.0p+2f;
    }
    var_f1 = 0x1.0p+4f;
    if (var_f1 <= var_f0)
    {
      return var_f1;
    }
    return var_f0;
  }
  if (fparg0 < 0x1.ep+4f)
  {
    var_f0 = (((0x1.ep+4f - fparg0) * 0x1.8p+1f) / 0x1.ep+3f) + 0x1.0p+0f;
    if (var_f0 <= 0x1.0p+0f)
    {
      var_f0 = 0x1.0p+0f;
    }
    var_f1 = 0x1.0p+2f;
    if (var_f1 <= var_f0)
    {
      return var_f1;
    }
    return var_f0;
  }
  if (fparg0 < 0x1.68p+6f)
  {
    var_f0 = 0x1.0p+0f - (((fparg0 - 0x1.ep+4f) * 0x1.CCCCCCp-1f) / 0x1.ep+5f);
    if (var_f0 <= 0x1.999998p-4f)
    {
      var_f0 = 0x1.999998p-4f;
    }
    if (var_f0 >= 0x1.0p+0f)
    {
      return 0x1.0p+0f;
    }
    return var_f0;
  }
  return 0x1.999998p-4f;
}

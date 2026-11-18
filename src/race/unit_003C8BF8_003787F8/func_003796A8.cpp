
typedef int s32;
typedef float f32;
struct func_003796A8_pt
{
  f32 x;
  f32 y;
};
extern s32 func_003796A8(s32 *arg0, struct func_003796A8_pt *arg1)
{
  s32 n = arg0[0];
  struct func_003796A8_pt *p;
  struct func_003796A8_pt *q;
  struct func_003796A8_pt *hi;
  s32 inside = 0;
  f32 *new_var;
  s32 k;
  q = (struct func_003796A8_pt *) (((char *) arg0) + 4);
  p = (struct func_003796A8_pt *) ((((char *) arg0) + (n * 8)) - 4);
  if (n > 0)
  {
    k = n;
    do
    {
      if ((*(new_var = &p->y)) != q->y)
      {
        hi = q;
        if (!(p->y < q->y))
        {
          hi = p;
          p = q;
        }
        if (p->y <= arg1->y)
        {
          if (arg1->y < hi->y)
          {
            f32 cr = ((arg1->x - p->x) * (hi->y - p->y)) - ((arg1->y - p->y) * (hi->x - p->x));
            if (0.0f < cr)
            {
              inside ^= 1;
            }
          }
        }
      }
      k--;
      p = q;
      q++;
    }
    while (k != 0);
  }
  return inside;
}

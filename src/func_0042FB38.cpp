
struct S
{
  char p[0x68];
  unsigned short seed;
};
inline int advance_seed(unsigned int arg0, unsigned int arg1)
{
  return (arg0 * arg1) + 12345;
}

unsigned int func_0042FB38(struct S *s)
{
  unsigned int n = s->seed;
  n = advance_seed(n, 1103515245U);
  n = (n >> 16) & 0x7fff;
  s->seed = n;
  return n;
}

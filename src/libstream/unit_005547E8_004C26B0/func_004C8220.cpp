/* compiler: ee-gcc2.96-no-strict-aliasing */

typedef struct Flags Flags;
struct Flags
{
  char pad0[0x1A];
  unsigned short bits;
  char pad1[0x27 - 0x1C];
  unsigned char a;
  unsigned char b;
  unsigned char c;
  char pad2[0x2E - 0x2A];
  unsigned char d;
  char pad3[0x98 - 0x2F];
  short e;
};
extern void func_004C8220(Flags *f, int flag)
{
  int new_var;
  Flags *new_var2;
  if (f->b)
  {
    f->c = 1;
  }
  else
  {
    f->a = 1;
  }
  new_var2 = f;
  new_var = 1;
  if (flag)
  {
    new_var2->d = (new_var2->e = new_var);
  }
  int v = new_var2->bits | 0xA;
  new_var2->bits = v - 8;
}

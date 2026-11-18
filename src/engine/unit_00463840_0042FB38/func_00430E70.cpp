
typedef unsigned char u8;
struct Sub
{
  char pad[0x487];
  u8 unk467;
};
extern void func_00430E70(void *arg0, int arg1)
{
  struct Sub *temp_v0 = (struct Sub *) (((char *) arg0) + 0x104);
  char *temp_a0 = ((char *) arg0) + 0x14;
  u8 temp_a3 = temp_v0->unk467;
  int lt7 = arg1 < 7;
  temp_v0->unk467 = (u8) arg1;
  if ((arg1 == 6) || ((lt7 && (arg1 == 5)) && (temp_a3 != 4)))
  {
    if (lt7 || temp_a3)
    {
      *((u8 *) (temp_a0 + 0x52)) = 0x78;
    }
    else
    {
      *((u8 *) (temp_a0 + 0x52)) = 0x78;
    }
  }
}

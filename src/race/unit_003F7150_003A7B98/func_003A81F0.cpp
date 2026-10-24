/* compiler: ee-gcc2.96-nogcse */

typedef struct Ring Ring;
typedef struct Obj Obj;
struct Ring
{
  int count;
  int pad4;
  int *entries;
};
struct Obj
{
  char pad0[0x60];
  Ring *ring;
};
extern int func_003A7FE8(int entry);
extern int func_003A81F0(Obj *o, int start)
{
  int i = 0;
  int count = o->ring->count;
  int divisor = count;
  if (count > 0)
  {
    int end = start + count;
    do
    {
      int index = (end - i) % divisor;
      i++;
      if (func_003A7FE8(o->ring->entries[index]))
      {
        return index;
      }
    }
    while (i < count);
  }
  return start;
}

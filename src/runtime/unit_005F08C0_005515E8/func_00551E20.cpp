struct Pair8 { int a, b; };
typedef bool (*Cmp)(const Pair8 &, const Pair8 &);

extern "C" void func_00551E20(Pair8 *first, int len, int top, Pair8 val, Cmp comp)
{
    int hole = len;
    int parent = (hole - 1) / 2;

    while (top < hole && comp(first[parent], val)) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = val;
}

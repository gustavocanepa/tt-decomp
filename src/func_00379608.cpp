/* compiler: ee-gcc2.96-no-strict-aliasing */
struct List { short pad; unsigned short count; int *items; };
extern "C" bool func_00379530(int, int, int, int) throw();
extern "C" bool func_00379608(List *l, int arg1, int arg2) {
    bool r = false;
    for (int i = 0; i < l->count; i++) r ^= func_00379530(l->items[i], i, arg1, arg2);
    return r;
}

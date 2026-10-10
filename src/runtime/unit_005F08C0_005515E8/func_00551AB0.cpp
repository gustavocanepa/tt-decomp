/* SGI STL __unguarded_insertion_sort_aux (stl_algo.h) for an 8-byte element with a function
   pointer comparison; the per-element __unguarded_linear_insert instance is func_00551DA8. */
struct Elem {
    int key;
    int value;
};

typedef bool (*Compare)(const Elem &, const Elem &);

extern "C" void func_00551DA8(Elem *last, Elem val, Compare comp);

extern "C" void func_00551AB0(Elem *first, Elem *last, Elem *, Compare comp)
{
    for (Elem *i = first; i != last; ++i)
        func_00551DA8(i, Elem(*i), comp);
}

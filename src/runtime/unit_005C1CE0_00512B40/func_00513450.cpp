/* SGI STL __final_insertion_sort (stl_algo.h) for a 20-byte element; __insertion_sort is
   func_00515B90, __unguarded_insertion_sort_aux func_00515E58. The comparator is passed as a
   one-byte struct whose byte is really copied (an empty struct would pass zeros), and
   __VALUE_TYPE(first) takes first by reference (the dead 4($sp) spill). */
struct Elem { int w[5]; };
struct Comp { char c; bool operator()(const Elem &, const Elem &) const; };
extern "C" void func_00515B90(Elem *first, Elem *last, Comp comp);
extern "C" void func_00515E58(Elem *first, Elem *last, Elem *, Comp comp);
template <class T> inline T *value_type(T *const &) { return (T *)0; }
template <class Iter, class C> inline void unguarded_insertion_sort(Iter first, Iter last, C comp)
{
    func_00515E58(first, last, value_type(first), comp);
}

extern "C" void func_00513450(Elem *first, Elem *last, Comp comp)
{
    if (last - first > 16) {
        func_00515B90(first, first + 16, comp);
        unguarded_insertion_sort(first + 16, last, comp);
    } else
        func_00515B90(first, last, comp);
}

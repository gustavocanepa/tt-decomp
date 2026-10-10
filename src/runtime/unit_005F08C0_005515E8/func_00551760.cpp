/* compiler: ee-gcc2.96-stl */
struct Elem {
    int a;
    int b;
};

typedef bool (*Less)(const Elem &, const Elem &);

extern "C" void func_005519A0(Elem *first, Elem *last, Less comp);
extern "C" void func_00551AB0(Elem *first, Elem *last, Elem *type, Less comp);

template <class Iter> inline Elem *value_type(const Iter &) { return (Elem *)0; }

static inline void unguarded_insertion_sort(Elem *first, Elem *last, Less comp)
{
    func_00551AB0(first, last, value_type(first), comp);
}

extern "C" void func_00551760(Elem *first, Elem *last, Less comp)
{
    if (last - first > 16) {
        func_005519A0(first, first + 16, comp);
        unguarded_insertion_sort(first + 16, last, comp);
    } else
        func_005519A0(first, last, comp);
}

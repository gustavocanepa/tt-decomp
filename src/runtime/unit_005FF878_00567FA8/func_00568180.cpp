/* compiler: ee-gcc2.96-stl */
/* SGI STL lexicographical_compare with a comparison function, instantiated for char ranges. */
extern "C" bool func_00568180(const char *first1, const char *last1, const char *first2,
                              const char *last2, bool (*comp)(char, char))
{
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (comp(*first1, *first2))
            return true;
        if (comp(*first2, *first1))
            return false;
    }
    return first1 == last1 && first2 != last2;
}

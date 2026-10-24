/* compiler: ee-gcc2.96-stl */
/* SGI STL find() for random-access iterators (loop unrolled by four), instantiated for an
   array of 8-byte entries compared by their second word. */
struct Entry {
    int key;
    int value;
};

inline bool operator==(const Entry &e, const int &v) { return e.value == v; }

extern "C" Entry *func_00567298(Entry *first, Entry *last, int value)
{
    int trip_count = (last - first) >> 2;
    for (; trip_count > 0; --trip_count) {
        if (*first == value) return first;
        ++first;
        if (*first == value) return first;
        ++first;
        if (*first == value) return first;
        ++first;
        if (*first == value) return first;
        ++first;
    }
    switch (last - first) {
    case 3:
        if (*first == value) return first;
        ++first;
    case 2:
        if (*first == value) return first;
        ++first;
    case 1:
        if (*first == value) return first;
        ++first;
    case 0:
    default:
        return last;
    }
}

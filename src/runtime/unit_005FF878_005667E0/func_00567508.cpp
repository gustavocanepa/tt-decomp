/* compiler: ee-gcc2.96-stl */
/* SGI STL lower_bound (with a comparison object) instantiated for 0x50-byte records ordered by
   the C string stored at +0x44. */
struct Record {
    char pad[0x44];
    const char *name;
    char pad2[0x50 - 0x48];
};

struct ByName {
    bool operator()(const Record &r, const char *const &key) const;
};

extern "C" int func_004A8268(const char *a, const char *b);

inline bool ByName::operator()(const Record &r, const char *const &key) const
{
    return func_004A8268(r.name, key) < 0;
}

static inline void advance(Record *&it, int n) { it += n; }
static inline void distance(Record *first, Record *last, int &n) { n += last - first; }

extern "C" Record *func_00567508(Record *first, Record *last, const char *const &key, ByName comp)
{
    int len = 0;
    Record *middle = first;
    int half;
    distance(first, last, len);
    while (len > 0) {
        half = len >> 1;
        middle = first;
        advance(middle, half);
        if (comp(*middle, key)) {
            first = middle;
            ++first;
            len = len - half - 1;
        } else {
            len = half;
        }
    }
    return first;
}

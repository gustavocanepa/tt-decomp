/* compiler: ee-gcc2.96-stl */
/* SGI STL lower_bound (comparison object passed by reference) for 12-byte records. */
struct Record {
    int w0, w4, w8;
};

struct Matcher {
    int pad0;
    int count;
};

extern "C" int func_0043B510(const Record *rec, const char *key, int count);

static inline int matches(const Record &r, const char *const &key, const Matcher &m)
{
    return func_0043B510(&r, key, m.count);
}

static inline void advance(Record *&it, int n) { it += n; }
static inline void distance(Record *first, Record *last, int &n) { n += last - first; }

extern "C" Record *func_005682C0(Record *first, Record *last, const char *const &key, const Matcher &m)
{
    int len = 0;
    Record *middle = first;
    int half;
    distance(first, last, len);
    while (len > 0) {
        half = len >> 1;
        middle = first;
        advance(middle, half);
        if (matches(*middle, key, m)) {
            len = len - half - 1;
            first = middle;
            ++first;
        } else {
            len = half;
        }
    }
    return first;
}

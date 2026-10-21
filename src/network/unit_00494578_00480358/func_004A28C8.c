/* compiler: ee-gcc2.96-no-strict-aliasing */
struct encoding;
static int func_004A28C8(const struct encoding *enc, const char *ptr1, const char *end1, const char *ptr2) {
    int c = *ptr2;
    unsigned int current = c;
    for (; c; ptr1 += 2, c = current = (unsigned char)*++ptr2) {
        if (ptr1 == end1) return 0;
        if (!(ptr1[0] == 0 && ptr1[1] == (char)current)) return 0;
    }
    return ptr1 == end1;
}

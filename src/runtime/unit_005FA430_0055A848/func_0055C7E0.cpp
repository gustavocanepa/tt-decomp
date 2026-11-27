/* compiler: ee-gcc2.96-stl */
/* Same bounded-array insertion algorithm as 00608B20, for 32 entries. */
struct IntArray { int items[0x20]; int count; };
static inline int *uninitialized_copy(int *first, int *last, int *result) {
    for (; first != last; ++first, ++result)
        if (result) *result = *first;
    return result;
}
extern "C" void *func_004F6574(void *, const void *, unsigned) throw();
static inline int *copy_backward(int *first, int *last, int *result) {
    int n = last - first;
    func_004F6574(result - n, first, n * sizeof(int));
    return result - n;
}
extern "C" void func_0055C8B8(int *first, int *last, const int *value);
extern "C" void func_0055C7E0(IntArray *a, int *pos, int n, const int *value) {
    uninitialized_copy(a->items + a->count - n, a->items + a->count, a->items + a->count);
    copy_backward(pos, a->items + a->count - n, a->items + a->count);
    func_0055C8B8(pos, pos + n, value);
    a->count += n;
}

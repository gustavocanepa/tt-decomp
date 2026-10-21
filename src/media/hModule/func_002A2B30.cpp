/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_002C10F0(void *);
extern "C" void func_002C1148(void *);
extern "C" void func_0054BB10(void *, const void *);
struct Object { char pad[0x10]; int word; void *handle; char string[0x10]; int field28; };
static inline void assignWord(int *dst, const int *src) {
    if (dst != src) *dst = *src;
}
static inline void assignHandle(void **dst, void *const *src) {
    if (dst != src) {
        if (*src) func_002C10F0(*src);
        if (*dst) func_002C1148(*dst);
        *dst = *src;
    }
}
static inline void assignString(void *dst, const void *src) {
    if (dst != src) func_0054BB10(dst, src);
}
extern "C" Object *func_002A2B30(Object *dst, const Object *src) {
    if (dst != src) {
        assignWord(&dst->word, &src->word);
        assignHandle(&dst->handle, &src->handle);
        assignString(dst->string, src->string);
        dst->field28 = 0;
    }
    return dst;
}

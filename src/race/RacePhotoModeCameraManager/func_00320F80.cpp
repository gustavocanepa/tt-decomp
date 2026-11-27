/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
extern "C" void func_004751FC(void);
static inline void *get(void *o) {
    char *e = *(char **)o + 0x210;
    void *fn = *(void **)(e + 4);
    return ((void *(*)(void *))fn)((char *)o + *(s16 *)e);
}
static inline void call(void *o) {
    char *e = *(char **)o + 0x70;
    void *fn = *(void **)(e + 4);
    ((void (*)(void *))fn)((char *)o + *(s16 *)e);
}
extern "C" void func_00320F80(void *self) {
    void *obj = get(self);
    if (obj == 0) return func_004751FC();
    call(obj);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
extern "C" void func_004751FC(void);
extern "C" void func_00475440(void *);
static inline void *get(void *o) {
    char *e = *(char **)o + 0x208;
    void *fn = *(void **)(e + 4);
    return ((void *(*)(void *))fn)((char *)o + *(s16 *)e);
}
static inline void call(void *o) {
    char *e = *(char **)o + 0x70;
    void *fn = *(void **)(e + 4);
    ((void (*)(void *))fn)((char *)o + *(s16 *)e);
}
extern "C" void func_00320E78(void *self) {
    void *obj = get(self);
    void *dst = (char *)self + 0xB00;
    if (obj == 0) return func_004751FC();
    func_00475440(dst);
    call(obj);
    func_00475440((char *)self + 0xB40);
}

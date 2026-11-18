/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int dummy; unsigned char *begin; unsigned char *end; unsigned char *cap; };
extern "C" void *func_004F64C4(void *, const void *, unsigned int);
extern "C" void *func_004F6574(void *, const void *, unsigned int) throw();
extern "C" void func_0051CF80(Vec *, unsigned char *, unsigned int, const unsigned char *);
extern "C" void func_002CC890(char *o, const void *src, unsigned int n) {
    unsigned char zero = 0;
    Vec *v = (Vec *)(o + 0xF8);
    unsigned char *end = v->end;
    unsigned int size = end - v->begin;
    if (n < size) {
        unsigned char *p = v->begin + n;
        func_004F6574(p, end, 0);
        v->end -= end - p;
    } else {
        func_0051CF80(v, end, n - size, &zero);
    }
    func_004F64C4(v->begin, src, n);
}

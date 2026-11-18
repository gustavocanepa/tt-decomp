/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
union Record { struct { unsigned char kind; char pad[3]; short first,last; }; int words[2]; };
struct Buf { char pad[8]; u16 *text; char tail[0x410]; };
struct S { char pad[0x85C]; int current; };
static inline int smaller(int a, int b) { return a < b ? a : b; }
extern "C" void func_00482178(S *s, Record *r, u16 *dst, int max) {
    Buf *b = (Buf *)((char *)s + (1 - s->current) * 0x41c + 0x24);
    int cap = max - 1;
    int len = r->last - r->first;
    int n = smaller(len, cap);
    for (int i = 0; i < n; i++) dst[i] = b->text[(short)(u16)r->first + i];
    dst[n] = 0;
}

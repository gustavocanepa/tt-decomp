/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Q { char d[0x41]; };
struct S { int w0, w1, w2, w3; unsigned char c; Q q; };
extern "C" void func_0047B410(S *a, S *b) {
    a->w0 = b->w0;
    a->w1 = b->w1;
    a->w2 = b->w2;
    a->w3 = b->w3;
    a->c = b->c;
    a->q = b->q;
}

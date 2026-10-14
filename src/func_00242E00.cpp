/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x, y; int pad[2]; };
extern "C" void func_00242010(void *, void *) throw();
extern "C" void func_00241FB8(void *, int) throw();
extern "C" void func_00299B08(void *, void *);
extern "C" void func_00299AB0(void *, int);
extern "C" float func_0029B188(void *);
extern "C" void func_00245BB0(void *, int, Vec *);
extern "C" void MImageFace__set_texcoord_bottom(void *ret, void *ctx, int n, void *args) {
    if (n > 0) {
        void *h[4];
        void *v[4];
        Vec a, b;
        func_00242010(h, ctx);
        void **pv = v;
        func_00299B08(pv, args);
        float f = func_0029B188(*pv);
        Vec *pa = &a;
        Vec *pb = &b;
        pa->x = 0.0f;
        pa->y = f;
        pb->x = 1.0f;
        pb->y = f;
        func_00245BB0(*h, 3, pa);
        func_00245BB0(*h, 2, pb);
        func_00299AB0(pv, 2);
        func_00241FB8(h, 2);
    }
}

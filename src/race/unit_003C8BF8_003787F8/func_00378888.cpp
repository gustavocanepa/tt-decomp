/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x,y; };
static inline float root(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r):"f"(x)); return r; }
extern "C" float func_00378888(V *a,V *b,V *c) {
    float bx=b->x-a->x;
    float by=b->y-a->y;
    float cx=c->x-a->x;
    float cy=c->y-a->y;
    float p=root(bx*bx+by*by)*root(cx*cx+cy*cy);
    if(p<=0.0f) return 0.0f;
    return (bx*cx+by*cy)/p;
}

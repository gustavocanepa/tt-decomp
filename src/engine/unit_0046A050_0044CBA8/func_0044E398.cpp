/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vec4 {float x,y,z,w;};
static inline float mul(float a,float b) { a *= b; return a; }
static inline float negmul(float a,float b) { a = -a; a *= b; return a; }
extern "C" void func_004A6328(float *,float *,float);
extern "C" void func_0044E398(Vec4 *a,float ang) {
    float sc[2];
    Vec4 r __attribute__((aligned(16)));
    func_004A6328(&sc[0],&sc[1],ang*0.5f);
    float x=a->x,z=a->z,w=a->w,y=a->y;
    Vec4 *p=&r;
    p->x=mul(sc[1],x)+mul(sc[0],z);
    p->y=mul(sc[0],w)+mul(sc[1],y);
    p->z=negmul(sc[0],x)+mul(sc[1],z);
    p->w=mul(sc[1],w)-mul(sc[0],y);
    *(u128*)a=*(u128*)p;
}

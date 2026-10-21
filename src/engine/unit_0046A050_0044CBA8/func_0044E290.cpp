/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q {union {u128 bits;struct {float x,y,z,w;} f;}; Q() {} Q(const Q &a) {bits=a.bits;} Q &operator=(const Q &a) {bits=a.bits;return *this;} };
extern "C" void func_004A6328(float *,float *,float);
extern "C" void func_0044E290(Q *a,float angle) {
 float sc[2]; Q r;
 func_004A6328(&sc[0],&sc[1],angle*0.5f);
 float w=a->f.w,x=a->f.x,y=a->f.y,z=a->f.z;
 float *px=&r.f.x;
 *px=sc[0]*w+sc[1]*x;
 float cy=sc[1],sz=sc[0]; cy*=y;sz*=z;cy-=sz;r.f.y=cy;
 float sy=sc[0],cz=sc[1]; sy*=y;cz*=z;sy+=cz;r.f.z=sy;
 float cw=sc[1],sx=sc[0]; cw*=w;sx*=x;cw-=sx;r.f.w=cw;
 *a=r;
}

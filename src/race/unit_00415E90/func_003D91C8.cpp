/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &o) { *(u128 *)this=*(const u128 *)&o; }
 V &operator=(const V &o) { *(u128 *)this=*(const u128 *)&o;return *this; }
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 V operator-(const V &v) const {V r(*this);r[0]-=v.x;r[1]-=v.y;r[2]-=v.z;return r;}
} __attribute__((aligned(16)));
struct Obj {char pad[0x30];V dir;float len,inv;};
extern "C" void func_003D9020(Obj *,const V *) throw();
static inline float squareRoot(float x) {float r;asm("sqrt.s %0, %1":"=f"(r):"f"(x));return r;}
extern "C" void func_003D91C8(Obj *o,const V *a,const V *b) {
 func_003D9020(o,a);
 V *d=&o->dir;
 *d=*b-*a;
 float len=squareRoot(d->x*d->x+d->y*d->y+d->z*d->z);
 o->len=len;
 if(len==0.0f) o->inv=0.0f;
 else o->inv=1.0f/len;
}

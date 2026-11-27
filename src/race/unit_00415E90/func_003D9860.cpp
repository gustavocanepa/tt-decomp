/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vec {
 union { u128 q; struct { float x,y,z,w; }; };
 float &operator[](int i) {return *(float*)((char*)this+i*4);}
 const float &operator[](int i) const {return *(const float*)((const char*)this+i*4);}
 Vec() {} Vec(const Vec &v) { q=v.q; }
 Vec &operator=(const Vec &v) {q=v.q;return *this;}
 Vec &operator*=(float s) {x*=s;y*=s;z*=s;return *this;}
 Vec operator*(float s) const {Vec r(*this);r*=s;return r;}
 Vec &operator+=(const Vec &v) {(*this)[0]+=v[0];(*this)[1]+=v[1];(*this)[2]+=v[2];return *this;}
 Vec operator+(const Vec &v) const {Vec r(*this);r+=v;return r;}
};
struct Point {u128 q; Point(const Vec &v):q(v.q){} Point(const Point &v):q(v.q){} };
struct Obj {char pad[0x50];Vec a,b;};
extern "C" void func_003D94B8(Obj*,Obj*,Obj*,float) throw();
extern "C" void func_003D9A80(Obj*,Point);
extern "C" void func_003D9A90(Obj*,Point);
extern "C" void func_003D9860(Obj *o,Obj *a,Obj *b,float t) {
 func_003D94B8(o,a,b,t);
 float s=1.0f-t;
 func_003D9A80(o,a->a*s+b->a*t);
 func_003D9A90(o,a->b*s+b->b*t);
}

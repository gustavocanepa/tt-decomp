/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_004A5D18(float) throw();
extern "C" float func_004EE530(float);

static inline float min_s(float a, float b)
{
    float r;
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
static inline float max_s(float a, float b)
{
    float r;
    __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}

struct Quat {
 float x,y,z,w;
 float &X() {return x;} float &Y() {return y;} float &Z() {return z;} float &W() {return w;}
 const float &X() const {return x;} const float &Y() const {return y;} const float &Z() const {return z;} const float &W() const {return w;}
 Quat() {}
 float &operator[](const int &i) {return (&x)[i];}
 const float &operator[](const int &i) const {return (&x)[i];}
 Quat(const Quat &o) {x=o.X(); y=o.Y(); z=o.Z(); w=o.W();}
 Quat &operator=(const Quat &o) {x=o.X(); y=o.Y(); z=o.Z(); w=o.W(); return *this;}
 Quat &operator*=(float s) {x*=s; y*=s; z*=s; w*=s; return *this;}
 Quat &operator+=(const Quat &o) {x+=o.X(); y+=o.Y(); z+=o.Z(); w+=o.W(); return *this;}
 Quat operator*(float s) const {Quat r=*this; r*=s; return r;}
 Quat operator+(const Quat &o) const {Quat r=*this; r+=o; return r;}
 Quat(float a,float b,float c,float d) {X()=a;Y()=b;Z()=c;W()=d;}
 Quat operator-() const {Quat r(-(*this)[0],-(*this)[1],-(*this)[2],-(*this)[3]); return r;}
 float dot(float a,float b,float c,float d) const {return x*a+y*b+z*c+w*d;}
 float dot(const Quat &o) const {return dot(o.X(),o.Y(),o.Z(),o.W());}
};

extern "C" void func_004534F0(Quat *out, const Quat *a, const Quat *b, float t)
{
    if (t == 0.0f) {
        *out = *a;
        return;
    }
    if (t == 1.0f) {
        *out = *b;
        return;
    }
    float d = a->dot(*b);
    if (d < 0.0f) {
        Quat nb = -*b;
        func_004534F0(out, a, &nb, t);
        return;
    }
    float th = 1.5707963f - func_004EE530(min_s(max_s(d, -1.0f), 1.0f));
    float s = func_004A5D18(th);
    if (s != 0.0f) {
        float inv = 1.0f / s;
        float k1 = func_004A5D18(th * (1.0f - t)) * inv;
        float k2 = func_004A5D18(th * t) * inv;
        *out = *a * k1 + *b * k2;
    } else {
        *out = *a;
    }
}

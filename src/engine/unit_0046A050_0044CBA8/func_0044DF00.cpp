/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Quat {float x,y,z,w;};
struct Col { float *p; Col(float *v):p(v){} Col(const Col& v):p(v.p){} float &operator[](int i) const {return p[i*4];} };
struct Mat {float a[16]; Col operator[](int i) {return Col(a+i);} };
extern "C" void func_0044E9D8(Quat *,float,float,float);
extern "C" float func_004A5B78(float,float);
extern "C" float func_004EE530(float);
extern "C" void func_0044DF00(Quat *q,Mat *m) {
    float a=func_004A5B78((*m)[2][1],(*m)[2][2]);
    float b=func_004EE530(-(*m)[2][0]);
    func_0044E9D8(q,a,b,func_004A5B78((*m)[1][0],(*m)[0][0]));
}

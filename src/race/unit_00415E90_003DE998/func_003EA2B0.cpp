/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Row3 { float *p; Row3(float *v):p(v) {} Row3(const Row3 &r):p(r.p) {} float &operator[](int n) { return p[n*3]; } };
struct Row4 { float *p; Row4(float *v):p(v) {} Row4(const Row4 &r):p(r.p) {} float &operator[](int n) { return p[n*4]; } };
struct Mat3 {
 union { float m[12]; u128 q[3]; };
 Mat3() {}
 Mat3(const Mat3 &r) { q[0]=r.q[0]; q[1]=r.q[1]; q[2]=r.q[2]; }
 Mat3 &operator=(const Mat3 &r) { q[0]=r.q[0]; q[1]=r.q[1]; q[2]=r.q[2]; return *this; }
 Row3 operator[](int n) { return Row3(m+n); }
};
struct Mat4 { float m[16]; Row4 operator[](int n) { return Row4(m+n); } };
extern "C" Mat3 func_0044D540(Mat3 *);
extern "C" void func_003EA148(Mat4 *,void *) throw();
extern "C" void func_003EA2B0(Mat4 *out,void *pos,Mat3 *rot) {
 Mat3 m;
 m=func_0044D540(rot);
 float zero=0.0f;
 float one=1.0f;
 (*out)[0][0]=m[0][0];
 (*out)[0][1]=m[0][1];
 (*out)[0][2]=m[0][2];
 (*out)[0][3]=zero;
 (*out)[1][0]=m[1][0];
 (*out)[1][1]=m[1][1];
 (*out)[1][2]=m[1][2];
 (*out)[1][3]=zero;
 (*out)[2][0]=m[2][0];
 (*out)[2][1]=m[2][1];
 (*out)[2][2]=m[2][2];
 (*out)[2][3]=zero;
 (*out)[3][0]=zero;
 (*out)[3][1]=zero;
 (*out)[3][2]=zero;
 (*out)[3][3]=one;
 func_003EA148(out,pos);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row {
 float *p;
 Row(float *q):p(q) {}
 Row(const Row &r):p(r.p) {}
 float &operator[](int n) { return p[n*2]; }
};
struct Mat {
 float v[4];
 Row operator[](int n) { return Row(v+n); }
};
static inline int iszero(float f) { int r=1; if (f!=0.0f) r=0; return r; }
static inline float subtract(float a, float b) { return a-b; }
extern "C" int func_003E8728(Mat *in, Mat *out) {
 float d=subtract((*in)[0][0]*(*in)[1][1],(*in)[0][1]*(*in)[1][0]);
 if (iszero(d)) return 0;
 d=1.0f/d;
 (*out)[0][0]=(*in)[1][1];
 (*out)[0][1]=-(*in)[0][1];
 (*out)[1][0]=-(*in)[1][0];
 (*out)[1][1]=(*in)[0][0];
 out->v[0]*=d;
 out->v[1]*=d;
 out->v[2]*=d;
 out->v[3]*=d;
 return 1;
}

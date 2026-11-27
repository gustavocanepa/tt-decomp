/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row {
 float *p;
 Row(float *q):p(q){}
 Row(const Row &r):p(r.p){}
 ~Row(){}
 float &operator[](int n){return p[n*4];}
};
struct ConstRow {
 const float *p;
 ConstRow(const float *q):p(q){}
 ConstRow(const ConstRow &r):p(r.p){}
 ~ConstRow(){}
 float operator[](int n) const {return p[n*4];}
};
struct Mat {
 float v[16];
 Row operator[](int n){return Row(v+n);}
 ConstRow operator[](int n) const {return ConstRow(v+n);}
};
static inline int iszero(float f) { int r=1; if (f!=0.0f) r=0; return r; }
extern "C" int func_003E8B70(const Mat *in, Mat *out) {
 float s0=(*in)[0][0]*(*in)[1][1]-(*in)[1][0]*(*in)[0][1];
 float c5=(*in)[2][2]*(*in)[3][3]-(*in)[3][2]*(*in)[2][3];
 float s1=(*in)[0][0]*(*in)[2][1]-(*in)[2][0]*(*in)[0][1];
 float c4=(*in)[1][2]*(*in)[3][3]-(*in)[3][2]*(*in)[1][3];
 float s2=(*in)[0][0]*(*in)[3][1]-(*in)[3][0]*(*in)[0][1];
 float c3=(*in)[1][2]*(*in)[2][3]-(*in)[2][2]*(*in)[1][3];
 float s3=(*in)[1][0]*(*in)[2][1]-(*in)[2][0]*(*in)[1][1];
 float c2=(*in)[0][2]*(*in)[3][3]-(*in)[3][2]*(*in)[0][3];
 float s4=(*in)[1][0]*(*in)[3][1]-(*in)[3][0]*(*in)[1][1];
 float c1=(*in)[0][2]*(*in)[2][3]-(*in)[2][2]*(*in)[0][3];
 float s5=(*in)[2][0]*(*in)[3][1]-(*in)[3][0]*(*in)[2][1];
 float c0=(*in)[0][2]*(*in)[1][3]-(*in)[1][2]*(*in)[0][3];
 float det=s0*c5-s1*c4+s2*c3+s3*c2-s4*c1+s5*c0;
 if (iszero(det)) return 0;
 float inv=1.0f/det;
 (*out)[0][0]=((*in)[1][1]*c5+(*in)[3][1]*c3-(*in)[2][1]*c4)*inv;
 (*out)[0][1]=((*in)[2][1]*c2-(*in)[3][1]*c1-(*in)[0][1]*c5)*inv;
 (*out)[0][2]=((*in)[0][1]*c4+(*in)[3][1]*c0-(*in)[1][1]*c2)*inv;
 (*out)[0][3]=((*in)[1][1]*c1-(*in)[2][1]*c0-(*in)[0][1]*c3)*inv;
 (*out)[1][0]=((*in)[2][0]*c4-(*in)[1][0]*c5-(*in)[3][0]*c3)*inv;
 (*out)[1][1]=((*in)[0][0]*c5+(*in)[3][0]*c1-(*in)[2][0]*c2)*inv;
 (*out)[1][2]=((*in)[1][0]*c2-(*in)[3][0]*c0-(*in)[0][0]*c4)*inv;
 (*out)[1][3]=((*in)[0][0]*c3+(*in)[2][0]*c0-(*in)[1][0]*c1)*inv;
 (*out)[2][0]=((*in)[1][3]*s5-(*in)[2][3]*s4+(*in)[3][3]*s3)*inv;
 (*out)[2][1]=(-(*in)[0][3]*s5+(*in)[2][3]*s2-(*in)[3][3]*s1)*inv;
 (*out)[2][2]=((*in)[0][3]*s4-(*in)[1][3]*s2+(*in)[3][3]*s0)*inv;
 (*out)[2][3]=((*in)[1][3]*s1-(*in)[0][3]*s3-(*in)[2][3]*s0)*inv;
 (*out)[3][0]=(-(*in)[1][2]*s5+(*in)[2][2]*s4-(*in)[3][2]*s3)*inv;
 (*out)[3][1]=((*in)[0][2]*s5-(*in)[2][2]*s2+(*in)[3][2]*s1)*inv;
 (*out)[3][2]=((*in)[1][2]*s2-(*in)[0][2]*s4-(*in)[3][2]*s0)*inv;
 (*out)[3][3]=((*in)[0][2]*s3-(*in)[1][2]*s1+(*in)[2][2]*s0)*inv;
 return 1;
}

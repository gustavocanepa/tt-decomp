/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float sqrtf_(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct Mat3 { float m[9]; float &at(int r, int c) { return m[r*3+c]; } };
struct Quat {
 float q[4];
 float &operator[](int n) { return q[n]; }
 Quat(Mat3 *m);
};
inline Quat::Quat(Mat3 *m) {
 float a=m->at(0,0), b=m->at(1,1);
 float t=a+b+m->at(2,2);
 if (t>=1.0f) {
  float s=4.0f/(*this)[3];
  (*this)[0]=(m->at(2,1)-m->at(1,2))*s;
  (*this)[1]=(m->at(0,2)-m->at(2,0))*s;
  (*this)[2]=(m->at(1,0)-m->at(0,1))*s;
  (*this)[3]=sqrtf_(t)*0.5f;
 } else if (t>=0.0f) {
  int i;
  if (a<b) i=1; else i=0;
  if (m->at(i,i)<m->at(2,2)) i=2;
  int j=(i+1)%3;
  int k=(j+1)%3;
  float s=m->at(i,i)-m->at(j,j)-m->at(k,k)+1.0f;
  if (s>=0.0f) {
   float v=sqrtf_(s)*0.5f;
   (*this)[i]=v;
   s=1.0f/(v*4.0f);
   (*this)[j]=(m->at(j,i)+m->at(i,j))*s;
   (*this)[k]=(m->at(k,i)+m->at(i,k))*s;
   (*this)[3]=(m->at(k,j)-m->at(j,k))*s;
  }
 }
}
extern "C" Quat func_003E6388(Mat3 *m) { return Quat(m); }

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vec {
 union { u128 q; struct {float x,y,z,w;} f; };
 Vec() {}
 Vec(float x,float y,float z,float w) {f.x=x;f.y=y;f.z=z;f.w=w;}
 Vec(const Vec &o) {q=o.q;}
 float &operator[](int i) {return *(float *)((char *)this+i*4);}
 Vec operator-() const {Vec r; r[0]=-f.x; r[1]=-f.y; r[2]=-f.z; r[3]=f.w; return r;}
};
struct Mat {
 u128 row[4];
 Mat() {}
 Mat(const Mat &o) {row[0]=o.row[0];row[1]=o.row[1];row[2]=o.row[2];row[3]=o.row[3];}
 Mat &operator=(const Mat &o) {row[0]=o.row[0];row[1]=o.row[1];row[2]=o.row[2];row[3]=o.row[3];return *this;}
};
extern "C" Mat func_003E61A8(const Vec &,float,float,float) throw();
extern "C" void func_003EA478(Mat *,const Vec *) throw();
extern "C" void func_003EA498(Mat *out,const Vec *pos,const Vec *rot) {
 *out=func_003E61A8(-*rot,0.0f,0.0f,0.0f);
 func_003EA478(out,pos);
}

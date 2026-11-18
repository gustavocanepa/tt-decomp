/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Matrix {
 float m0; int z4,z8,zC,z10; float m14; int z18,z1C,z20,z24;
 float m28; int z2C; float m30,m34,m38,m3C;
};
extern "C" void func_00475440(void *);
extern "C" void func_004738A0(float l,float r,float b,float t,float n,float f) {
 Matrix m;
 m.z4=0; m.z8=0; m.zC=0; m.z10=0;
 m.z18=0; m.z1C=0; m.z20=0; m.z24=0;
 m.z2C=0;
 m.m0=2.0f/(r-l);
 m.m14=2.0f/(t-b);
 m.m28=-2.0f/(f-n);
 m.m30=(l+r)/(l-r);
 m.m34=(b+t)/(b-t);
 m.m38=(n+f)/(n-f);
 m.m3C=1.0f;
 func_00475440(&m);
}

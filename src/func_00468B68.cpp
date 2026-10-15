struct Matrix{float v[16];};
extern "C" void func_004752F8(Matrix*);
extern "C" void func_0047525C(Matrix*);
extern "C" void func_00468B68(float shift){Matrix m;func_004752F8(&m);float c=m.v[10],d=m.v[14];float b=d/(c-1)+shift;float a=d/(c+1)+shift;float nd=a*-2;float nc=a+b;nd*=b;float denominator=a-b;nc=-nc;float newd=nd/denominator;float newc=nc/denominator;m.v[10]=newc;m.v[14]=newd;func_0047525C(&m);}

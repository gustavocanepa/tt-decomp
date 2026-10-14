/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_005F7E78[];
extern "C" void func_0046F0F8(int);
extern "C" void func_00473A08(int,int,void *);
extern "C" void func_00473AD0(int,void *);
extern "C" void func_00478C98(int);
struct Vec { float x,y,z,w;
 Vec(float a,float b,float c,float d) : x(a),y(b),z(c),w(d) {}
 void set(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
};
extern "C" void func_0039E4D8(void) {
 func_00473AD0(0,D_005F7E78);
 Vec v(0.3f,0.3f,0.3f,1.0f);
 func_00473A08(102,0,&v);
 v.set(0.5f,0.5f,0.5f,0.5f); func_00473A08(102,1,&v);
 v.set(0.5f,0.5f,0.5f,0.5f); func_00473A08(102,4,&v);
 v.set(0.0f,1.0f,0.0f,0.0f); func_00473A08(102,13,&v);
 func_00478C98(101); func_0046F0F8(102); func_00478C98(103); func_00478C98(104); func_00478C98(8);
}

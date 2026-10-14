/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { char pad[12]; float fov; };
struct Mat { char pad[0x44]; float x,y,z; char rest[0x30]; } __attribute__((aligned(8)));
extern "C" void func_003A6AC0(Mat *,int);
extern "C" void func_00322698(Cam *,float) throw();
extern "C" void func_0032DA40(Cam *p,Mat *src) {
 Mat tmp=*src;
 tmp.x=0x1.999998p-4f;
 tmp.y=500.0f;
 tmp.z=1.0f;
 func_003A6AC0(&tmp,1);
 func_00322698(p,p->fov);
}

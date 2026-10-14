/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam { char pad[12]; float fov; char pad10[0x68]; float target; };
struct Mat { char pad[0x44]; float x,y,z; char rest[0x30]; } __attribute__((aligned(8)));
extern "C" float func_004A5DE0(float);
extern "C" void func_003A67B8(Mat *,int);
extern "C" void func_00322698(Cam *,float) throw();
extern "C" void func_00322F00(Cam *self,Mat *src,float a) {
 Mat tmp;
 float t = self->fov + (self->target-self->fov)*a;
 tmp=*src;
 float z = 1.0f/func_004A5DE0(t*0.5f*0x1.1df468p-6f);
 tmp.x=src->x;
 tmp.y=src->y;
 tmp.z=z;
 func_003A67B8(&tmp,1);
 func_00322698(self,t);
}

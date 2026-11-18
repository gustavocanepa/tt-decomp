/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Quat { float x,y,z,w; };
struct Vec4 { float x,y,z,w; };
extern "C" void func_00450F30(const Quat *q,Vec4 *out,float w4) {
 float x=q->x,y=q->y,z=q->z,w=q->w;
 float xx=x*x,zz=z*z,yw=y*w,zw=z*w,xy=x*y,xz=x*z;
 out->w=w4;
 out->x=2.0f*(0.5f-y*y-zz);
 out->y=2.0f*(xy+zw);
 out->z=2.0f*(xz-yw);
}

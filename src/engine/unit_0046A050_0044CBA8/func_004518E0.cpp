/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 {float x,y,z,w;};
extern "C" void func_004A6328(float *,float *,float);
extern "C" void func_004518E0(Vec4 *a,float ang) {
    float sc[2];
    Vec4 r;
    func_004A6328(&sc[0],&sc[1],ang*0.5f);
    float w=a->w,x=a->x,y=a->y,z=a->z;
    float *px=&r.x,*py=&r.y,*pz=&r.z;
    *px=sc[0]*w+sc[1]*x;
    *py=sc[1]*y-sc[0]*z;
    *pz=sc[0]*y+sc[1]*z;
    r.w=sc[1]*w-sc[0]*x;
    a->w=r.w;
    float rx=*px,ry=*py,rz=*pz;
    a->y=ry;
    a->z=rz;
    a->x=rx;
}

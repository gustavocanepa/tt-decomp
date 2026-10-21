/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x,y,z,w; };
extern "C" void func_00452498(Vec4 *,float,float) throw();
extern "C" void func_004509C0(Vec4 *, const Vec4 *) throw();
extern "C" void func_00452570(Vec4 *a,float b,float c) {
    Vec4 t; Vec4 *tp=&t; Vec4 q; Vec4 v;
    func_00452498(&t,b,c);
    Vec4 *vp=&v;
    vp->x=tp->x; v.y=tp->y; v.z=tp->z; v.w=tp->w;
    func_004509C0(vp,a);
    float *px=&q.x;
    int ky=4,kz=8,kw=12;
    float *py=(float*)((char*)&q+ky), *pz=(float*)((char*)&q+kz), *pw=(float*)((char*)&q+kw);
    *px=vp->x; *py=v.y; *pz=v.z; *pw=v.w;
    a->x=*px; a->y=q.y; a->z=q.z; a->w=q.w;
}

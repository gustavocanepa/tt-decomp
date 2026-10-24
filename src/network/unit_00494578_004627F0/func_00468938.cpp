/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x,y,z; };
extern "C" void func_00468890(Vec3 *, float,float,float) throw();
extern "C" void func_004688D0(Vec3 *,Vec3 *,Vec3 *) throw();
extern "C" void func_00475440(void *);
extern "C" void func_004755EC(float,float,float);
extern "C" void func_00468938(float x,float y,float z,float tx,float ty,float tz,float ux,float uy,float uz) {
 float m[16]; Vec3 f,up,u,r;
 func_00468890(&f,tx-x,ty-y,tz-z);
 up.x=ux;up.y=uy;up.z=uz;
 func_004688D0(&r,&f,&up);
 func_00468890(&r,r.x,r.y,r.z);
 func_004688D0(&u,&r,&f);
 m[0]=r.x;m[4]=r.y;m[8]=r.z;
 m[1]=u.x;m[5]=u.y;m[9]=u.z;
 m[2]=-f.x;m[6]=-f.y;m[10]=-f.z;
 m[12]=0;m[13]=0;m[14]=0;m[15]=1;
 m[3]=0;m[7]=0;m[11]=0;
 func_00475440(m);
 func_004755EC(-x,-y,-z);
}

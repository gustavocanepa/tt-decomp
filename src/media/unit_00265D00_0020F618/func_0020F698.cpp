/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec {
 float x,y,z,w;
 Vec(float a,float b,float c,float d) {x=a;y=b;z=c;w=d;}
 Vec(const Vec &v) {x=v.x;y=v.y;z=v.z;w=v.w;}
};
struct Obj { char pad[0xA8]; Vec *p; };
extern "C" void func_00205E20(void *,float *,float *) throw();
extern "C" Vec func_0020F698(Obj *self) {
 float size[2];
 func_00205E20(self,size,size+1);
 Vec *p=self->p;
 Vec res(0.0f,0.0f,size[0],size[1]);
 if(p) {
  if(size[0]>0.0f || size[1]>0.0f) {
   res.x=p->x*size[0];
   res.y=p->y*size[1];
   res.z=p->z*size[0];
   res.w=p->w*size[1];
  }
 }
 return res;
}

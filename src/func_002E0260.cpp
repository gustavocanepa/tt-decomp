struct Vec{float x,y,z;};
struct Self{char unknown0[0x1c];Vec linear,angular;char unknown34[0x10];unsigned char index;};
struct Params{char unknown0[3];signed char count;float ix,iy,iz;char unknown10[0x84];float mass;};
extern char* D_0061B704;extern float D_005F2BBC;
extern "C" void func_002DF380(Self*,int,const Vec*);
extern "C" void func_002DED58(Self*);
inline float inverseRoot(float a,float b){float r;__asm__("rsqrt.s %0,%1,%2":"=f"(r):"f"(a),"f"(b));return r;}
inline Params*params(Self*s){return (Params*)(D_0061B704+160*s->index+32);}
inline float energy(Self*s){Params*p=params(s);return p->ix*s->angular.x*s->angular.x+p->iy*s->angular.y*s->angular.y+p->iz*s->angular.z*s->angular.z+p->mass*(s->linear.x*s->linear.x+s->linear.y*s->linear.y+s->linear.z*s->linear.z);}
void func_002E0260(Self*s,const Vec*points,float x,float z){
 float square=x*x+z*z;x=-x;float r=inverseRoot(1.0f,square);Vec normal;normal.x=z*r;normal.y=0;normal.z=x*r;
 int best=0;float value=D_005F2BBC;int count=params(s)->count;
 for(int i=0;i<count;i++){float d=normal.x*points[i].x+normal.y*points[i].y+normal.z*points[i].z;if(d<value){value=d;best=i;}}
 float old=energy(s);func_002DF380(s,best,&normal);
 if(old<energy(s)){s->angular.x=0;s->angular.y=0;s->angular.z=0;s->linear.x=0;s->linear.y=0;s->linear.z=0;}
 func_002DED58(s);
}

extern char D_00604CB0[];
extern void func_00465838(void*,void*,void*,int,float,float,float);
extern "C" void func_00465F98(void* a,void* b,float x,float y,float z,float scale) {
 scale*=0.5f;
 return func_00465838(a,b,D_00604CB0,0,x*scale,y*scale,z*scale);
}

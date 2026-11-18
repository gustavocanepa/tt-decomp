struct TextureState { unsigned long words[5]; };
struct Texture { char physicalPrefix[24];TextureState*state; };
extern "C" int func_00467728(Texture*);
extern "C" void func_0046AC48(TextureState*);
extern "C" void func_00472268(unsigned,int);
extern "C" float func_0038F448(float,float,unsigned);
extern "C" void func_0038EE10(float,float,float,float,float,float,float,float);
// PLZCW is the EE packed leading-sign-count hardware operation.
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
// Drawing helpers' incidental results are not consumed by this physical view.
extern "C" void func_0038EA20(Texture*t,float x,float y,unsigned xf,unsigned yf,int filter,int blend){
 if(t){func_00467728(t);func_0046AC48(t->state);func_00472268(2,filter);func_00472268(3,blend);
 unsigned long bits=t->state->words[4];unsigned width=(bits>>14&1023)+1;unsigned height=(bits>>34&1023)+1;
 float w=(int)width,h=(int)height;float left=func_0038F448(x,w,xf),top=func_0038F448(y,h,yf);
 float right=left+w,bottom=top+h;float u=(float)width/(float)extentPower(width),v=(float)height/(float)extentPower(height);
 func_0038EE10(left,top,right,bottom,0,0,u,v);
 }
}

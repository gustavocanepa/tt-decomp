/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TextureState { unsigned long words[5]; };
struct Texture { char prefix[24]; TextureState *state; };
extern "C" int func_00467728(Texture*);
extern "C" void func_0046AC48(TextureState*);
extern "C" void func_0038EE10(float,float,float,float,float,float,float,float);
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
extern "C" void func_0038E480(Texture*t,float x,float y,float scale){
 if(t){func_00467728(t);func_0046AC48(t->state);
 scale*=0.5f;
 unsigned long bits=t->state->words[4];
 unsigned width=(bits>>14&1023)+1,height=(bits>>34&1023)+1;
 float w=(int)width,h=(int)height;
 float dx=w*scale,dy=h*scale;
 float u=(float)width/(float)extentPower(width),v=(float)height/(float)extentPower(height);
 func_0038EE10(x-dx,y-dy,x+dx,y+dy,0,0,u,v);
 }
}

typedef unsigned char u8;
struct Input;
extern float func_003BCC90(Input*);
extern float func_003BCC50(Input*);
extern float func_003BCC40(Input*);
extern float func_003BCC00(Input*);
extern float func_003BCFA0(Input*);
extern float func_003BCF50(Input*);
#define F(p,n) (*(float*)((u8*)(p)+(n)))
#define I(p,n) (*(int*)((u8*)(p)+(n)))
inline float maxf(float x,float y){float r;asm("max.s %0,%1,%2":"=f"(r):"f"(x),"f"(y));return r;}
inline float minf(float x,float y){float r;asm("min.s %0,%1,%2":"=f"(r):"f"(x),"f"(y));return r;}
extern "C" void func_003661F0(int mode,void*out,Input*input){
 F(out,4)=func_003BCC90(input);I(out,0)=1;
 if(mode==3){float v=func_003BCC50(input);F(out,12)=0;F(out,16)=v;}
 else if(mode==4){F(out,16)=0;F(out,12)=func_003BCC50(input);}
 else if(mode==5){F(out,16)=0;F(out,12)=func_003BCC50(input);}
 else{F(out,16)=func_003BCC40(input)*3.14f*.0625f;F(out,12)=func_003BCC50(input)*3.14f*.0625f;}
 if(mode==1){
  F(out,88)=func_003BCC00(input);F(out,92)=func_003BCC00(input);
  float angle=F(out,4);
  if(angle<0)F(out,88)*=1-minf(maxf(-angle/1.5707963f,0),1)*.5f;
  else F(out,92)*=1-minf(maxf(angle/1.5707963f,0),1)*.5f;
  I(out,84)=1;
 }else if(mode==3){F(out,88)=func_003BCFA0(input);F(out,92)=func_003BCF50(input);I(out,84)=1;}
 else I(out,84)=0;
}

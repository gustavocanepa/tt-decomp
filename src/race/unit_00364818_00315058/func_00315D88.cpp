struct Self;
extern float D_00582E7C,D_00582E84;
extern unsigned char D_00582E7A;
#define F(p,o) (*(float*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned int*)((char*)(p)+(o)))
extern "C" float func_00315D88(Self*self,float x,float y,float z){
 char*p=(char*)self+0x104;
 char*spec=*(char**)((char*)self+0x10);
 float steer=F(p,0x5AC);
 if(steer<0)steer=-steer;
 float weight;
 if(steer<=D_00582E7C)weight=1;else if(steer>=1)weight=D_00582E84;
 else weight=1-(1-D_00582E84)*(steer-D_00582E7C)/(1-D_00582E7C);
 float low=F(p,0x54C);
 float base=F(p,0x550)-low;
 if(base<0)base=-base;
 base*=F(spec,0x244);
 if(!B(p,0x540))x=-x;
 if(D_00582E7A && x<0)return -97999.9921875f;
 float enabled=F(spec,0x248);
 if(enabled!=0){
 if((U(p,0x540)&0x00ff00ff)==0x10000)return 97999.9921875f;
 int mode=B(p,0x542);
 if(!mode)return 97999.9921875f;
 if(weight==1){
 if(mode==2)return 97999.9921875f;
 if(F(p,0x4AC)>.75f)return 97999.9921875f;
 y=(x+y)+z;
 if(x>0 && y>0)return 97999.9921875f;
 if(x<0 && y<0)return 97999.9921875f;
 }
 }
 base*=weight;
 if(base>=1){base=97999.9921875f;if(enabled==0)base=1;}
 return base;
}

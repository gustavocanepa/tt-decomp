struct State { unsigned long words[5]; };
struct Texture { char pad[24]; State *state; };
struct Obj { char p0; unsigned char xf,yf,p3; short x,y,w,h; float alpha; Texture *tex; int p14; int enabled,color; int colors[4]; };
extern char D_005F56B0[];
extern int D_005F56C0[4][2];
extern "C" Texture *func_00357310(const char*);
extern "C" int func_001048C8(void*,int,int,int);
extern "C" void func_00104C88(void*);
extern "C" void func_00104D10(void*);
extern "C" void func_00104868(void*,int);
extern "C" void func_00477DC0(int);
extern "C" void func_00470450(int);
extern "C" void func_00478C98(unsigned);
extern "C" void func_00472268(int,int);
extern "C" int func_00467728(Texture*);
extern "C" void func_0046AC48(State*);
extern "C" void func_00474288(int,int,int,int,int,int,int,int);
extern "C" int func_0038F5F8(int,float);
extern "C" void func_00473F50(int,int,int,int);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void func_0046F0F8(unsigned);
extern "C" void func_004702D8(int,float);
extern "C" int func_0038F4A8(int,int,int);
extern "C" void func_0038EE10(float,float,float,float,float,float,float,float);
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
extern "C" void RaceTireWearDisplay__render_main(Obj*self,void*ctx){
 int buf[16];
 if(self->enabled){
 Texture *t=self->tex;
 if(!t){t=func_00357310(D_005F56B0);self->tex=t;}
 unsigned long bits=t->state->words[4];
 unsigned width=(bits>>14&1023)+1,height=(bits>>34&1023)+1;
 func_001048C8(buf,0,width,height);func_00104C88(buf);
 func_00477DC0(self->color);func_00470450(-1);func_00478C98(6);
 func_00472268(2,0);func_00472268(3,0);
 func_00467728(self->tex);func_0046AC48(self->tex->state);
 func_00474288(0,0,width,height,0,0,width,height);
 for(int i=0;i<4;i++){
 func_00477DC0(func_0038F5F8(self->colors[i],self->alpha));
 int x=D_005F56C0[i][0],y=D_005F56C0[i][1];
 func_00473F50(x,y,x+6,y+11);
 }
 func_00104C88(ctx);func_00104D10(buf);
 func_00477E30(1,1,1,self->alpha);func_0046F0F8(6);func_004702D8(0x44,0);
 func_00472268(2,1);func_00472268(3,1);
 float u=(float)width/(float)extentPower(width),v=(float)height/(float)extentPower(height);
 float x=func_0038F4A8(self->x,self->w,self->xf);
 float y=func_0038F4A8(self->y,self->h,self->yf);
 func_0038EE10(x,y,x+(float)self->w,y+(float)self->h,0,0,u,v);
 func_00104868(buf,2);
 }
}

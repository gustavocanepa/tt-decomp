/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta,index; void (*fn)(void *,...); };
struct VF { short delta,index; void (*fn)(void *,float); };
struct R { short delta,index; char *(*fn)(void *,int); };
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern "C" void func_002F2140(void *,int);
extern "C" int func_0031C798(char *,int);
extern "C" int func_0033A0F0(void *) throw();
extern "C" void func_00346DE8(int);
extern "C" void func_00346E68(int);
extern "C" void func_0034A858(void *,float);
extern "C" void func_0034DB40(void *,void *);
extern "C" void func_00375CB8(void *);
extern "C" void func_00375DE0(void *);
extern "C" void func_00376C18(void *,float,float);
extern "C" int RaceBase__updateReplayEndingFrames(void *);
static inline char *get(char *s,int off,int a) { R *e=(R *)(F(s,char *,0x64)+off); return e->fn(s+e->delta,a); }
static inline bool exceeds(int n,int limit) { return n>limit; }
extern "C" void func_0033C1C8(char *s) {
 char *race=F(s,char *,0x6c);
 char *input=get(s,0xd0,0);
 if((unsigned)F(s,int,0xD8C)>=2) func_00346DE8(func_0031C798(input,0));
 if(F(s,int,0xE0C)==0) {
  char *p=F(s,char *,0x74);
  func_00375CB8(race);
  V *e=(V *)(F(p,char *,4)+0x10); e->fn(p+e->delta);
  if(F(s,int,0xD94)==0) func_00346E68((unsigned)F(s,int,0xD8C)>=2);
  float dt=0x1.11111p-6f;
  func_0034A858(F(F(s,char *,0x6c),void *,0x80),dt);
  char *a=F(F(F(s,char *,0x6c),char *,0x80),char *,4);
  func_0034DB40(F(a,void *,0x80),a);
  func_002F2140(F(s,void *,0x70),0);
  VF *ef=(VF *)(F(s,char *,0x64)+0x158); ef->fn(s+ef->delta,dt);
  func_00375DE0(race);
  char *replay=get(s,0x240,0x100);
  if((unsigned)(F(s,int,0xD8C)-2)<2) {
   int frame=F(replay,int,0x11c); F(s,int,0xDEC)=frame;
   int flag=1; if(!(F(race,float,0xd4)>=0.0f)) flag=0;
   if(flag==0 && F(race,int,0xe0)==0) {
    if(F(s,int,0xE18)==0) {
     int left=F(s,int,0xDF0)-frame;
     if(exceeds(left,60)) { } else func_00376C18(race,(float)left*dt,1.0f);
    } else func_0033A0F0(s);
   }
  }
  if(RaceBase__updateReplayEndingFrames(replay)==0) F(s,int,0xDF4)=0;
 }
 V *e=(V *)(F(input,char *,0)+0xB8); e->fn(input+e->delta,race,F(s,void *,0x70),F(s,int,0xE08)==0);
}

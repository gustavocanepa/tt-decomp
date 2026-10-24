/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
extern unsigned int D_0076D0F0[];
// Provisional packet descriptor layout; c/d/e meanings remain unknown.
struct Header { char pad[8]; unsigned char a,b; short c,d,e; unsigned *data; short size,z; };
extern Header D_0076D550;
// Size is stored in 16-byte units. Both pointers address the static packet buffer.
inline void initializePacketDescriptor(Header *h,unsigned *end,int c,int e,int d,unsigned *data) { h->a=0; h->b=0; h->c=c; h->d=d; h->e=e; h->data=data; h->size=(end-data)/4; h->z=0; }
inline unsigned *appendWord(unsigned *p,unsigned v) { *p=v; return p+1; }
inline unsigned *appendFloat(unsigned *p,float v) { *(float*)p=v; return p+1; }
extern "C" void func_004649B0() {
 // Build the static command packet and seven overlapping three-vertex sectors.
 unsigned *p=D_0076D0F0;
 p=appendWord(p,0x6c01c0c0); p=appendWord(p,0x801c); p=appendWord(p,0x30264000); p=appendWord(p,0x412); p=appendWord(p,0); p=appendWord(p,0x6208c040);
 *(unsigned char*)p=7;
 int i;
 for(i=6;i>=0;i--) ((unsigned char*)p)[i+1]=6;
 p+=2; p=appendWord(p,0x681cc000);
 unsigned *q=p;
 for(i=0;i<7;i++) {
  for(int j=0;j<3;j++) {
   int index=i*2+j;
   float angle;
   if(index!=14) angle=(2.0f*(float)index*3.1415926f)/14.0f; else angle=0;
   q=appendFloat(q,func_004A5C50(angle)); q=appendFloat(q,func_004A5D18(angle)); q=appendWord(q,0);
   if(j==0) { q=appendWord(q,0); q=appendWord(q,0); q=appendWord(q,0); }
  }
 }
 p=q;
 p=appendWord(p,0x6e1cc080);
 for(i=0;i<28;i++) { int v=(i&3)==1 ? -1 : 0; unsigned *dst=p; p++; *dst=v; }
 while((p-D_0076D0F0)&3) p=appendWord(p,0);
 initializePacketDescriptor(&D_0076D550,p,1,14,28,D_0076D0F0);
}

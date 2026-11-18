/* compiler: ee-gcc2.96-as2004 */
typedef unsigned int u32;
struct __attribute__((packed)) HeaderS { char magic[4]; u32 size; short w,h; char rest[4]; unsigned char flags; };
struct __attribute__((packed)) HeaderU { char magic[4]; u32 size; unsigned short w,h; char rest[4]; };
extern "C" {
int func_004A81B8(const void *, const void *, u32);
int func_004FB300(int);
int func_004FB368(int);
int func_004FA710();
int func_004FA510(int, void (*)(), int, int);
int func_004FA540(int, void (*)(), int, int);
int func_004FA520(int,int);
int func_004FA550(int,int);
int func_004FA5A0(int,void (*)(),int);
int func_004FA5B0(int);
void func_004FA740();
int func_004FA770(int);
void func_004FAAA0(int);
void func_004CC438();
void func_004CC6A8();
void func_004BAE78();
void func_004CC168(u32);
int func_005038D8();
int func_00503928();
int func_004BAB78(u32,u32);
void func_004BADF8();
void func_004BAD30();
void func_004BAE40();
extern char D_00613210[];
extern int D_00776B84;
}
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")

extern "C" int func_004BA678(int mode,u32 dest,unsigned char *data,...) {
 u32 size, pixels;
 unsigned char flags;
 if(func_004A81B8(data,D_00613210,4)) return -1;
 switch(mode) {
 case 0: { HeaderS *h=(HeaderS *)data; data+=16; size=h->size-16; pixels=h->w*h->h*4; flags=h->flags; break; }
 case 1: { HeaderU *h=(HeaderU *)data; data+=16; size=h->size-16; pixels=h->w*h->h*4; flags=0; break; }
 default: return -1;
 }
 func_004FB300(8);
 {
 u32 s=REG(0x1000E010);
 REG(0x1000E010)=8; (void)REG(0x1000E010); SYNC();
 if(s&0x80000) { REG(0x1000E010)=0x80000; (void)REG(0x1000E010); SYNC(); }
 u32 s2=REG(0x1000E010);
 REG(0x1000E010)=16; (void)REG(0x1000E010); SYNC();
 if(s2&0x100000) { REG(0x1000E010)=0x100000; (void)REG(0x1000E010); SYNC(); }
}
 int thread=func_004FA710();
 int handler1=func_004FA510(8,func_004BADF8,0,thread);
 int handler2=func_004FA540(3,func_004BAD30,0,thread);
 func_004CC438();
 func_004BAE78();
 func_004CC168(0);
 REG(0x1000B400)&=~12; SYNC();
 REG(0x1000B410)=(u32)data&0xfffffff; SYNC();
 REG(0x1000B420)=((size+15)>>4)+1; SYNC();
 func_004FAAA0(0); SYNC();
 func_005038D8();
 u32 old=REG(0x1000F520);
 REG(0x1000F590)=old|0x10000; (void)REG(0x1000F590); SYNC();
 REG(0x1000B400)|=0x100; (void)REG(0x1000B400); SYNC();
 REG(0x1000F590)=old&~0x10000; (void)REG(0x1000F590); SYNC();
 func_00503928();
 func_004BAB78(dest,pixels);
 while((int)REG(0x10002010)<0) {}
 func_004CC6A8();
 while((int)REG(0x10002010)<0) {}
 REG(0x10002010)=(flags&0xfb)<<16; SYNC();
 while((int)REG(0x10002010)<0) {}
 func_004FB368(8);
 REG(0x10002000)=(((flags>>2)&1)<<24)|0x10010000; SYNC();
 D_00776B84=func_004FA5A0(1000,func_004BAE40,thread);
 func_004FA740();
 func_004FA5B0(D_00776B84);
 func_004FA770(thread);
 int result=0;
 u32 state=REG(0x10002010);
 if(state&0x4000) result=-1;
 if(state&0x80000000) result=-1;
 func_004CC438();
 func_004FB300(8);
 func_004BAE78();
 {
 u32 s=REG(0x1000E010);
 REG(0x1000E010)=8; (void)REG(0x1000E010); SYNC();
 if(s&0x80000) { REG(0x1000E010)=0x80000; (void)REG(0x1000E010); SYNC(); }
 u32 s2=REG(0x1000E010);
 REG(0x1000E010)=16; (void)REG(0x1000E010); SYNC();
 if(s2&0x100000) { REG(0x1000E010)=0x100000; (void)REG(0x1000E010); SYNC(); }
}
 func_004FA520(8,handler1);
 func_004FA550(3,handler2);
 return result;
}

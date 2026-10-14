typedef unsigned char u8;typedef unsigned short u16;typedef unsigned u32;
struct Self;
struct Row{u8 bytes[16];};
struct Rng {u32 state;Rng(u32) asm("func_00544038");};
extern void func_003FE6A8(Self*);
extern float func_005357F8(Rng*);
inline u32 count(Self*s){return *(u32*)s;}
inline Row&row(Self*s,u32 i){return ((Row*)((u8*)s+16))[i];}
extern "C" void func_003FE7B0(Self*s){
 u32 i=0;func_003FE6A8(s);
 for(;i<count(s);++i)row(s,i).bytes[10]=255;
 Rng r(*(u16*)((u8*)s+8));*(u16*)((u8*)s+4)=0;
 u32 assigned=0;
 i=0;for(;i<count(s);++i){
  float f=func_005357F8(&r);u32 size=count(s);u32 index=(u32)(f*(float)size);
  u32 n=0;
  for(;n<size;++n){
   Row&e=row(s,index);if(e.bytes[9] && (signed char)e.bytes[10]<0)break;
   ++index;if(index>=size)index=0;
  }
  Row&e=row(s,index);if((signed char)e.bytes[10]<0)e.bytes[10]=assigned++;
 }
 *(u16*)((u8*)s+8)=(u32)(func_005357F8(&r)*32768.f);
}

typedef unsigned char u8;typedef unsigned u32;
struct Self;struct Input;
extern u32 func_003EB970(Input*);
extern u32 func_003EB978(Input*);
#define word(s,n) (*(u32*)((u8*)(s)+(n)))
#define flt(s,n) (*(float*)((u8*)(s)+(n)))
extern "C" void func_003A62E0(Self*s){
 Input*input=*(Input**)((u8*)s+8);
 u32 pressed=func_003EB970(input),held=func_003EB978(input);
 word(s,16)=pressed;word(s,12)=held;
 if(held&0x400)word(s,40)=(word(s,40)&0xFFFFFF00)|1;
 if(held&0x800)word(s,40)=(word(s,40)&0xFF00FFFF)|0x10000;
 if(pressed&0x400)word(s,40)=(word(s,40)&0xFFFF00FF)|0x100;
 if(pressed&0x800)word(s,40)=(word(s,40)&0x00FFFFFF)|0x1000000;
 if(pressed&1)++((u8*)s)[44];
 if(pressed&2){int n=((u8*)s)[44];--n;((u8*)s)[44]=n;}
 if(pressed&16)flt(s,56)+=1;
 if(pressed&32)flt(s,56)-=1;
 if(pressed&256)flt(s,48)-=1;
 if(pressed&512)flt(s,48)+=1;
 if(pressed&128)flt(s,52)+=1;
 if(pressed&64)flt(s,52)-=1;
 float dx=*(float*)((u8*)input+0xDC);
 float x=flt(s,48),y=flt(s,52),z=flt(s,56);
 dx=dx+dx;x+=dx;flt(s,48)=x;
 float dy=*(float*)((u8*)input+0xE0);dy=dy+dy;y+=dy;flt(s,52)=y;
 float dz=*(float*)((u8*)input+0xE4);dz=dz+dz;z-=dz;flt(s,56)=z;
}

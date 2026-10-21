/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;typedef unsigned short u16;typedef long long s64;
extern u8 D_00586398[];
extern "C" s64 func_00506C58(s64,s64);
extern "C" int func_004348C0(u16 *data) {
 int total=0,denom=0;
 int i=0,off=0;
 int end;
 unsigned r;
 do {
  end=8;if(i<3)end=i+5;
  int start=i<5?0:i-4;
  if(start<end) {
   u8 weight=D_00586398[i];
   u16 *p=(u16 *)((off+start)*2+(int)data);
   start=end-start;
   int increment;
   do {
    unsigned a=p[0],b=p[64];
    int third=p[128];
    r=a<1025U?a:1024;
    total+=r*weight;increment = weight<<10;
    denom+=increment;
    r=b<1025U?b:1024;
    total+=r*weight;denom+=increment;
    r=(unsigned)third<257U?third:256;
    unsigned c=(u16)(r*4);
    r=c<1025U?c:1024;
    total+=r*weight;denom+=increment;
    start--;p++;
   }while(start!=0);
  }
  i++;off+=8;
 }while(i<8);
 total=(int)func_00506C58((s64)total*10000,denom);
 total=(total*70+(data[120]*10000/59160)*20+(data[184]*10000/59160)*10)/100;
 return total<=10000?total:10000;
}

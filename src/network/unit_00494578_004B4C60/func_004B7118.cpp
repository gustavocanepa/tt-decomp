/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned long u64;
struct Date { short year;u8 month,day,hour,minute,second; };
struct Raw {u8 b[8];};
struct Bytes {u64 a:8,b:8,c:8,d:8,e:8,f:8,g:8,h:8;};
union Value { Bytes b;u64 v; };
extern Raw D_006131B0,D_006131B8;
extern "C" int func_004B70D0(int) throw() __attribute__((const));
static inline u64 pack(Raw r) {Value v;v.b.a=r.b[0];v.b.b=r.b[1];v.b.c=r.b[2];v.b.d=r.b[3];v.b.e=r.b[4];v.b.f=r.b[5];v.b.g=r.b[6];v.b.h=r.b[7];return v.v;}
extern "C" Raw func_004B7118(Date *date) {
 int year=date->year;
 if(year<2000) return D_006131B0;
 if(year>=2100) return D_006131B8;
 Raw r;
 r.b[0]=0;
 r.b[1]=func_004B70D0(date->second);
 r.b[2]=func_004B70D0(date->minute);
 r.b[3]=func_004B70D0(date->hour);
 r.b[4]=0;
 r.b[5]=func_004B70D0(date->day);
 r.b[6]=func_004B70D0(date->month);
 r.b[7]=func_004B70D0(year-2000);
 return r;
}

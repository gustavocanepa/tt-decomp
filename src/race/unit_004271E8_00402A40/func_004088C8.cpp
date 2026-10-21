/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Spec { char pad[12]; short year; char rest[18]; };
struct Range { int low,high; };
struct Table { int ranges[15][2]; };
extern Table D_005FB8D0;
extern "C" void func_002E4610(void*,unsigned);
extern "C" void func_002E46E0(void*,float);
extern "C" void func_002E4800(void*,float);
extern "C" void func_002E4A08(void*,float);
extern "C" void func_002E4AE0(void*,float);
extern "C" void *func_00408B58(void*);
extern "C" int func_00408C18(void*,int);
extern "C" long func_0040CFE0(void*);
extern "C" int func_0040D360(void*);
extern "C" int func_004107B0(long,Spec*);
extern "C" void func_00544038(int*,int);
extern "C" float func_00535758(int*,float,float);
extern "C" void func_004088C8(char *self,int seed,int variation,int amount) {
 int rng[4]; Spec spec;
 char *sub=self+0x4E8;
 func_00544038(rng,seed);
 if(variation<0) variation=(int)func_00535758(rng,0.0f,(float)func_0040D360(func_00408B58(self)));
 func_00408C18(self,variation);
 if(amount<0) {
  func_004107B0(func_0040CFE0(func_00408B58(self)),&spec);
  int year=spec.year-1990;
  if(year<0) year=0;
  year=year>=15 ? 14 : year;
  amount=(int)func_00535758(rng,(float)(D_005FB8D0.ranges[year][0]*1000000),(float)(D_005FB8D0.ranges[year][1]*1000000));
 }
 float f=(float)amount;
 func_002E4610(sub,amount);
 func_002E46E0(sub,f);
 func_002E4AE0(sub,f);
 func_002E4800(sub,f);
 func_002E4A08(sub,f);
 func_002E4A08(sub,0.0f);
}

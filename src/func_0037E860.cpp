/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Text {long head;char eighth,ninth;} __attribute__((packed));
extern "C" Text D_005F73D8;
extern "C" const char D_005F73E8[],D_005F7400[];
extern "C" void func_004A6500(char*,const char*,...);
extern "C" void func_0037E860(char*out,unsigned time){
 if(time==0x157529ff){*(Text*)out=D_005F73D8;return;}
 unsigned milliseconds=time%1000;unsigned seconds=time/1000;
 unsigned second=seconds%60;unsigned minutes=seconds/60;
 unsigned minute=minutes%60;unsigned hours=minutes/60;
 if(hours!=0){func_004A6500(out,D_005F73E8,hours,minute,second,milliseconds);return;}
 func_004A6500(out,D_005F7400,minute,second,milliseconds);
}

struct Text {long head;char eighth,ninth;} __attribute__((packed));
extern "C" Text D_005F9630;
extern "C" const char D_005F9640[],D_005F9658[];
extern "C" int func_004A64A8(char*,unsigned,const char*,...);
extern "C" void GranTurismo4__GetTimeString(unsigned time,char*out,unsigned capacity){if(time==0x157529ff){*(Text*)out=D_005F9630;return;}unsigned milliseconds=time%1000;unsigned seconds=time/1000;unsigned second=seconds%60;unsigned minutes=seconds/60;unsigned minute=minutes%60;int hours=minutes/60;if(hours>0){func_004A64A8(out,capacity,D_005F9640,hours,minute,second,milliseconds);return;}func_004A64A8(out,capacity,D_005F9658,minute,second,milliseconds);}

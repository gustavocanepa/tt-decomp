extern float func_004308F0(float,float,float,float);
#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))
extern "C" void func_00430968(void* self,float value,float rate) {
 void* data=(char*)FIELD(void*,self,0xe8)+0x104;
 FIELD(float,self,0x34)=func_004308F0(FIELD(float,data,0x55C),value-0.55555556f,0.75f,rate);
 unsigned char type=FIELD(unsigned char,self,0x1e);
 if(type!=3 && type!=4){
  unsigned char mode=FIELD(unsigned char,data,0x487);
  if(mode<2 || mode>4) value+=5.5555548667907715f;
 }
 float result=FIELD(float,self,0x34);
 if(result==0.0f && value<FIELD(float,data,0x55C)) FIELD(float,self,0x38)=1.0f;
 if(result!=1.0f && result!=0.0f) FIELD(short,self,0x3c)=12;
}

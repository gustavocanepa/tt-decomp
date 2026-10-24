extern "C" void func_0040BCF0(void*);
inline void fillLong(long value,const int& count,unsigned char* self,const int& offset){int n=count-1;long* p=(long*)(self+offset);for(;n>=0;--n)*p--=value;}
inline void fillByte(const int& count,unsigned char* self,const int& offset){int n=count-1;unsigned char* p=self+offset;for(;n>=0;--n)*p--=0;}
extern "C" void func_00405700(unsigned char* self){unsigned char* p=self+8;for(int n=2;n>=0;--n){func_0040BCF0(p);p+=0x190;}fillLong(-1L,4,self,0x4D0);fillByte(12,self,0x4E7);*(int*)(self+0x4D8)=0;}

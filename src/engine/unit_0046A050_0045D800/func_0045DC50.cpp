extern unsigned char* func_0045DAB8(void*,const void*,int*);
extern int func_0045D908(const void*);
extern void* malloc(int);
extern void func_004B0A30(void*,void*,const void*,int);
extern void func_004B0AB8(void*,int);
extern "C" void* func_0045DC50(void* self,const void* name,int* allocated,int* size){
 unsigned char* source=func_0045DAB8(self,name,size);
 if(!source) return source;
 if(func_0045D908(source)){
 int length=source[4]|(source[5]<<8);
 length|=source[6]<<16;
 length|=source[7]<<24;
 length=-length;
 void* result=malloc(length);
 char decoder[0x1840];
 func_004B0A30(decoder,result,source,1);
 func_004B0AB8(decoder,2);
 *allocated=1;
 if(size) *size=length;
 return result;
 } else { *allocated=0;return source; }
}

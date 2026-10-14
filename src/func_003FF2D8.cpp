extern "C" void* func_004C9A38(void*,int);
extern "C" void func_003FF108(void*,int,void*);
extern "C" void func_003FF2D8(void* self,void* table,const signed char* ids,const unsigned char* keys,int count){for(int i=0;i<count;++i){void* entry=func_004C9A38(table,keys[i]);func_003FF108(self,ids[i],entry);}}

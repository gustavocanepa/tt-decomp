union Record{struct {unsigned char kind;char pad[3];short first,last;};int words[2];};
extern int func_00483480(void*,Record*);
#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))
inline Record* record(char* base,int i){unsigned int address=i*8;address+=(unsigned int)base;return (Record*)(address+0x218);}
extern "C" void func_00483570(void* self,int end,Record* item){
 int delta=end-item->last;
 item->last=end;
 int index=func_00483480(self,item)+1;
 char* bank=(char*)self+(1-FIELD(int,self,0x85C))*0x41c+0x24;
 for(;index<FIELD(int,bank,0x214);++index){
  Record* next=record(bank,index);
  next->first+=delta;next->last+=delta;
 }
}

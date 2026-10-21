/* compiler: ee-gcc2.96-no-strict-aliasing */
#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))
struct Record { unsigned char kind, flag; unsigned short id; short first,last; };
extern "C" Record *func_004831E8(void *,int) throw();
extern "C" Record *func_00483270(void *self,int index,int kind) {
 char *base=(char*)self+(1-FIELD(int,self,0x85C))*0x41c;
 int *count=(int*)(base+0x238);
 char *records=base+0x24;
 if(index>=*count) return func_004831E8(self,kind);
 for(int i=0;i<*count-index;i++) {
  char *position=records+(*count-i)*8;
  Record *src=(Record*)(position+0x210);
  Record *dst=(Record*)(position+0x218);
  dst->kind=src->kind;
  dst->flag=src->flag;
  dst->id=src->id;
  dst->first=src->first;
  dst->last=src->last;
 }
 ++*count;
 char *position=records+index*8;
 Record *dst=(Record*)(position+0x218);
 short prev=FIELD(short,position,0x224);
 dst->kind=kind;
 dst->first=prev;
 dst->last=prev;
 return dst;
}

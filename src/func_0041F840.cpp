struct Reader {void* buffer;int size;void* section;int count;void* table;};
struct Obj {char gap0[16];int size;char gap14[4];unsigned short countA,unknown1,countB,countC;char gap20[13];unsigned char flag;char gap2e[14];void** listA;void* field40;void*** listB;char gap48[24];void** source;char gap64[24];Obj** owner;};
extern "C" void func_004AFF60(Reader*);
extern "C" void func_004B00A0(Reader*,void*,int);
extern "C" void func_004B0430(Reader*);
extern "C" void* func_00466AE0(void*);
extern "C" void* func_00466B28(void*);
extern "C" void func_0041F840(Obj* self){
Reader reader;func_004AFF60(&reader);func_004B00A0(&reader,self,self->size);func_004B0430(&reader);
if(self->listA){for(int i=0;i<self->countA;i++)if(self->listA[i])func_00466AE0(self->listA[i]);}
if(self->listB){for(int j=0;j<self->countC;j++)if(self->listB[j])for(int i=0;i<self->countB;i++)if(self->listB[j][i])func_00466B28(self->listB[j][i]);}
self->flag=0;if(!self->field40)self->field40=*self->source;
*self->owner=self;
}

struct N{char pad[0x10];N*next;int flag;char*data;char pad1c[4];char object[1];};
struct L{int count;char pad[0x10];N*head;};
struct O{char pad[0x60];L*list;};
extern "C" void func_0036C1E8(L*);
extern "C" char *func_0040CF70(char*);
extern "C" void func_004F7B74(char*,char*);
extern "C" void func_0040D640(char*,char*);
extern "C" void func_0010EDB0(char*s,char*a){
 O*o=*(O**)(a+0x6c);
 func_0036C1E8(o->list);
 N*n=o->list->head;
 int i=0;
 if(o->list->count>0){
 int sentinel=0x157529ff;int*p=(int*)(s+0x458);char*aux=s+0x304;char*dst=s+4;
 do{
  char*ob=(char*)n+0xFD8;
  func_004F7B74(dst,func_0040CF70(ob));
  func_0040D640(ob,aux);aux+=0x10;
  char*d=n->data;
  if(*(unsigned char*)(d+0x5D6))*p=*(int*)(d+0x734);else *p=sentinel;
  if(!n->flag)*(int*)(s+0x4A4)=i;
  ++i;n=n->next;++p;dst+=0x80;
 }while(i<o->list->count);
 }
}

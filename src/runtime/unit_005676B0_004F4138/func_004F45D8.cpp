struct S{int x;char pad[0x28];int a,b,flag;};
extern "C" void func_004A59F0();extern "C" void func_004F42C8(int);
extern "C" void func_004F4568();
extern "C" int func_004F4700(void*,int,int,int,int,int,int,void(*)(),S*);
extern "C" int func_004F45D8(S*self,int a,int b,int c,int d){self->flag=b&1;while(func_004F4700((char*)self+4,a,b,self->a,self->b,c,d,func_004F4568,self))func_004A59F0();if(!self->flag)func_004F42C8(self->x);return 0;}

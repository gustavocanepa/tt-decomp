struct Obj{int a,mode;char data[96];int count;};
extern "C" int func_002E85F0(void*);
extern "C" void func_002E88B0(Obj*,int);
extern "C" int func_002E8FF0(Obj* self){int size=4;switch(self->mode){case 0:size+=func_002E85F0(self->data);break;case 1:for(int i=0;i<self->count;i++){func_002E88B0(self,i);size+=18836;size+=func_002E85F0(self->data);}break;case 2:size+=18836+func_002E85F0(self->data);break;}return size;}

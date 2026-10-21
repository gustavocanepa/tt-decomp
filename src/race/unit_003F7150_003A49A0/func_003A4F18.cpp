extern "C" int func_003A4DA0(void*,int);
extern "C" void func_003A4E80(void*),func_002E4EF0(void*,int),func_003052F0(void*,int,int,int);
struct Pair{int low,high;void set(int a,int b){low=a;high=b;}};
extern "C" void func_003A4F18(unsigned char* self,unsigned char* object,int kind){
 unsigned char* view=object+0x104;
 unsigned char* owner=*(unsigned char**)self;
 if(*(signed char*)(view+0x486)==2)return;
 switch(kind){case 3:case 4:case 6:{int mode=func_003A4DA0(self,1);if(!self[0x23920]&&mode==3)mode=1;func_003A4E80(self);func_002E4EF0(object,mode);break;}default:func_003A4E80(self);func_002E4EF0(object,2);break;}
 if(*(int*)(owner+0xdc)||view[0x461]||*(int*)(owner+0xf0))return;
 func_003052F0(owner,10,view[0x460],0);
 if(!self[0x20A24])((Pair*)(owner+0x88))->set(-1,0x157529ff);
}

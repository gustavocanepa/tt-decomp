extern "C" int func_00254218(char *) throw();
extern "C" void func_00255EA8(char *,int) throw();
extern "C" int func_00258090(char *,int);
extern "C" int func_00256038(char *self,int count) {
 int index=*(int *)(self+0x14C);
 if (index>=0) {
 if(count>0) {
 do {
 --index;
 if (index<0) {
 if (*(int *)(self+0x130)!=0) index=func_00254218(self)-1;
 else index=-1;
 if (index<0) return 0;
 }
 if (func_00258090(self,index)==0) {
 --count;
 if (index==*(int *)(self+0x14C)) index=-1;
 }
 if (index<0) return 0;
 } while(count>0);
 }
 if (index>=0) {func_00255EA8(self,index);return 1;}
 }
 return 0;
}

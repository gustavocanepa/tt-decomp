struct S {char pad[18];unsigned short count;};
extern "C" int func_004783E0(S *);
extern "C" int func_004782A8(unsigned,S *);
extern "C" void func_00466828(S *,int);
extern "C" void func_00467508(S *);
extern "C" void func_0046FB08(int);
extern "C" void func_00472628();
extern "C" int func_00467728(S *self){if(!self->count)return -1;int n=func_004783E0(self);if(n<0){n=func_004782A8(self->count<<6,self);if(n>=0){func_00466828(self,n);func_00467508(self);func_0046FB08(1);func_00472628();}}return n;}

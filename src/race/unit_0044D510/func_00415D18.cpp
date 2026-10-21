struct Owner {int unknown0;unsigned flags;float x,y;};
struct Display;
extern Display* D_00586EF4;
extern "C" void func_00415E70(Owner*,unsigned);
extern "C" void func_0045FE50(Display*,const char*,__builtin_va_list,int,int);
extern "C" void func_00415FC8(Owner*);
extern "C" void func_00415D18(Owner* self,const char* format,...) {
 func_00415E70(self,self->flags);
 __builtin_va_list args;__builtin_stdarg_start(args,format);
 func_0045FE50(D_00586EF4,format,args,1,0);
 __builtin_va_end(args);
 func_00415FC8(self);
}

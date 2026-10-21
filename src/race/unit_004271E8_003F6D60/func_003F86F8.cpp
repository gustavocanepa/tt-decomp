extern char D_005DCFA0[],D_005F9C50[];
extern "C" long long func_0040FBD8(const char *);
struct Slot;
extern "C" Slot* func_003F87E0(void*,long long);
extern "C" char *func_004F8588(char *,const char *,int);
extern "C" char *func_004F83D8(char *,const char *,int);
extern "C" Slot* func_003F86F8(void* self,const char *name){
 char buf[64];
 long long n=func_0040FBD8(name);
 if(n!=-1)return func_003F87E0(self,n);
 func_004F8588(buf,D_005DCFA0,64);func_004F83D8(buf,name,64);
 n=func_0040FBD8(buf);
 if(n!=-1)return func_003F87E0(self,n);
 func_004F8588(buf,D_005F9C50,64);func_004F83D8(buf,name,64);
 n=func_0040FBD8(buf);
 if(n!=-1)return func_003F87E0(self,n);
 return 0;
}

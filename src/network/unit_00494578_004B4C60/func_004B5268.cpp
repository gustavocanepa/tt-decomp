/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct State { u8 f[10]; char name[0x100]; char p10a[2]; int size; u8 option; char p111[3]; float x,y,z; };
struct Obj { char pad[0x30]; State state; };
struct Lock { void *p; char pad[12]; };
struct Args { int size,zero; char pad[8]; };
extern char D_00773E68[];
extern char D_006130C8[];
extern "C" void func_004AEAF8(Obj *);
extern "C" void func_004A4930(void *);
extern "C" void func_004A4970(void *);
extern "C" void func_004B5E10(float);
extern "C" void func_004B5D80(float);
extern "C" void func_004B5C98(float);
extern "C" int func_004A8368(const char *) throw();
extern "C" int func_004A8268(const char *,const char *) throw();
extern "C" char *func_004F7B74(char *,const char *) throw();
extern "C" void *func_0047DC60(void *,char *,Args *,int);
extern "C" void func_004B5B30(char *,int);
extern "C" void func_004B5C20();
extern "C" void func_004B5C48();
extern "C" void func_004B5C70();
extern "C" void func_004B5E98();
extern "C" void func_004B5268(Obj *o) {
 State st;
 Lock lock;
 char path[0x100];
 char temp[0x20];
 Args args;
 void *mutex=D_00773E68;
 for(;;) {
 func_004AEAF8(o);
 Lock *pl=&lock;
 pl->p=mutex;
 func_004A4930(mutex);
 st=o->state;
 o->state.f[0]=0;
 o->state.f[1]=0;
 o->state.f[3]=0;
 o->state.f[4]=0;
 o->state.f[5]=0;
 o->state.f[6]=0;
 o->state.f[7]=0;
 o->state.f[8]=0;
 o->state.f[9]=0;
 func_004A4970(pl->p);
 if(st.f[8]) func_004B5E10(st.z);
 if(st.f[7]) func_004B5D80(st.y);
 if(st.f[6]) func_004B5C98(st.x);
 if(st.f[1]) {
 if(st.size) {
 int len=func_004A8368(st.name);
 if(func_004A8268((char*)&st+len+6,D_006130C8)==0) {
 func_004F7B74(path,st.name);
 char *pt=temp;
 path[len-1]='m';
 Args *pa=&args;
 pa->size=st.size;
 pa->zero=0;
 func_0047DC60(pt,path,pa,1);
 }
 }
 func_004B5B30(st.name,st.option!=0);
 void *p=D_00773E68;
 pl->p=p;
 func_004A4930(p);
 if(o->state.f[1]==0) o->state.f[2]=1;
 func_004A4970(p);
 }
 if(st.f[4]) func_004B5C48();
 if(st.f[3]) func_004B5C20();
 if(st.f[5]) func_004B5C70();
 if(st.f[9]) func_004B5E98();
 }
}
extern "C" void func_005477C8(Obj *o) {func_004B5268(o);}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { unsigned len,cap,ref,sel; };
struct Str { char *p; };
struct Val { int type; float n; };
struct Input { int a,b; char *p; };
extern Rep D_005A4C58;
extern char D_00602218[];
extern "C" int func_00448410(void *) throw();
extern "C" int func_004A6500(char *,const char *,...);
extern "C" char *strobe__toUpper(Rep *);
extern "C" int func_004A8368(const char *) throw();
extern "C" Str *func_00550E18(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" void *func_00448048(void *,const Str &) throw();
extern "C" void *func_0043D3E0(void *,void *) throw();
extern "C" void func_004A45D0(void *) throw();
extern "C" void func_00447D00(Input *,int) throw();
extern "C" Val *func_0044C328(Val *out,char *owner,int flag,Input *in) {
 char buf[16];
 void *map=owner+4;
 int count=func_00448410(map);
 if(flag) {
  func_004A6500(buf,D_00602218,count++);
  Str key;
  Rep *r=&D_005A4C58;
  char *p=(char *)(r+1);
  Str *keyptr=&key;
  char *src=buf;
  if(r->sel) p=strobe__toUpper(r);
  else r->ref++;
  keyptr->p=p;
  func_00550E18(keyptr,0,-1,src,func_004A8368(src));
  func_0043D3E0(func_00448048(map,*keyptr),in->p-8);
  r=(Rep *)(keyptr->p-16);
  if(--r->ref==0) func_004A45D0(r);
 }
 func_00447D00(in,flag);
 out->type=6;out->n=(float)count;
 return out;
}

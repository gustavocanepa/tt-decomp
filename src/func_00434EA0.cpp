/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004A8368(const char *) throw();
extern "C" void func_004F8588(void *,const void *,int) throw();
extern "C" const char *func_00434EA0(char *buf,const char *name) {
 int len=func_004A8368(name);
 const char *end=name+len;
 if(end[-2]=='2' && end[-1]=='4') {
  func_004F8588(buf,name,len-2);
  (buf+len)[-2]=0;
  return buf;
 }
 return name;
}

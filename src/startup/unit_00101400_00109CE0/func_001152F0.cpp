struct Rep{int len,cap,ref,sel;};struct Str{char*p;};
extern char D_005DF6D0[];
extern "C" void func_001150E8(void*,void*);
extern "C" void func_00115090(void*,int);
extern "C" void func_002ADC48(void*,void*);
extern "C" void func_002ADBF0(void*,int);
extern "C" Str*func_002AFE68(int);
extern "C" void func_00116FD8(void*,const char*);
static inline const char*c_str(Str*s){int len=((Rep*)s->p)[-1].len;if(len==0)return D_005DF6D0;s->p[len]=0;return s->p;}
extern "C" void func_001152F0(void*,void*arg1,int,void*args){
  int buf0[4],buf1[4];int*ps;int self;
  func_001150E8(buf0,arg1);
  ps=buf1;
  func_002ADC48(ps,args);
  self=buf0[0];
  func_00116FD8((void*)self,c_str(func_002AFE68(*ps)));
  func_002ADBF0(ps,2);
  func_00115090(buf0,2);
}

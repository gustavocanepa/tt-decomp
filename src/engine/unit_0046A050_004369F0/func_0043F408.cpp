extern char D_00601618[],D_006014A0[];
struct S{int type;};
extern "C" char*strobe__Any__toString(S*);
extern "C" float func_0043E0B0(S*);
extern "C" void func_0043D7C8(S*,float),func_0043F580(S*);
extern "C" int func_004F7740(const char*,const char*,void*);
extern "C" void func_0043F408(S*s,int base){int n;float f;
 if((unsigned)(s->type-3)<2){char*p=strobe__Any__toString(s);if(p[0]=='0'&&(p[1]=='x'||p[1]=='X')){base=16;p+=2;}
 if(base==16){base=func_004F7740(p,D_00601618,&n);func_0043D7C8(s,(float)n);}else{base=func_004F7740(p,D_006014A0,&f);func_0043D7C8(s,f);}
 if((unsigned)(base+1)<2)func_0043F580(s);
 }else func_0043D7C8(s,func_0043E0B0(s));
}

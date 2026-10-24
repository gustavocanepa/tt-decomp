struct R{int a,b,refs,cap;};
struct Val;
extern "C" void func_0043D510(Val *);
struct Val { int type; int v; Val() : type(1) {} ~Val() { func_0043D510(this); } };
struct Str{char*p;Str(const char*);};
extern R D_005A4C58;extern char D_00601DF0[];
extern "C" char* strobe__toUpper(R*);extern "C" int func_004A8368(const char*);
extern "C" Str* func_00550E18(Str*,int,int,const char*,int);
extern "C" Val* func_00448190(void*,Str*);
extern "C" void func_0043DE58(Val*, int);
extern "C" Val* func_0043D3E0(Val*, Val*);
extern "C" void func_004A45D0(R*);
inline Str::Str(const char*c){R*r=&D_005A4C58;char*t=(char*)(r)+16;if(r->cap)t=strobe__toUpper(r);else ++r->refs;p=t;func_00550E18(this,0,-1,c,func_004A8368(c));}
struct O { char pad[0x14]; int f14; };
extern "C" void func_00448478(O *o, int a) {
    o->f14 = a;
    Val t;
    func_0043DE58(&t, a);
    Str v(D_00601DF0); Str *pv = &v;
    func_0043D3E0(func_00448190(o, &v), &t);
    R*r=(R*)pv->p-1;if(--r->refs==0)func_004A45D0(r);
}

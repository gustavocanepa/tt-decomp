struct N{char pad[0x14];void*object;};
struct Iter{N*p;Iter(){}Iter(N*n):p(n){}Iter(const Iter&o):p(o.p){}};
struct Tree{int pad;N*end;};
struct Str{char*p;};
extern "C" Iter find(Tree*,Str*) __asm__("func_0052AB58");
extern "C" char D_005EA078[],D_005EA050[],D_005EA088[];
extern "C" void func_00526860(const char*,const char*);
extern "C" void func_002C0FE8(void*),func_002C1050(void*);
inline bool different(const Iter&a,const Iter&b){return a.p!=b.p;}
inline const char*text(Str*s){int n=((int*)s->p)[-4];if(!n)return D_005EA050;s->p[n]=0;return s->p;}
inline void assign(void**to,void**from){if(to!=from){void*p=*from;if(p)func_002C0FE8(p);if(*to)func_002C1050(*to);*to=p;}}
extern "C" int func_001E9780(void*self,void**out,Str*key){Tree*t=(Tree*)((char*)self+280);Iter it=find(t,key);if(different(it,Iter(t->end))){func_00526860(D_005EA078,text(key));assign(out,&it.p->object);return 1;}func_00526860(D_005EA088,text(key));return 0;}

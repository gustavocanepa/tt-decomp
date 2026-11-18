/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep {unsigned len,cap,ref,selfish;};
struct String;
extern Rep D_005A4C58;
extern "C" char *strobe__toUpper(Rep *) throw();
extern "C" String *func_00550E18(String *,unsigned,unsigned,const char *,unsigned) throw();
extern "C" unsigned func_004A8368(const char *) throw();
extern "C" void free(void *) throw();
static inline char *grab(Rep *r){if(r->selfish)return strobe__toUpper(r);++r->ref;return (char *)(r+1);}
static inline void release(Rep *r){if(--r->ref==0)free(r);}
struct String {
 char *dat;
 Rep *rep()const{return (Rep *)dat-1;}
 String(const char *s){dat=grab(&D_005A4C58);func_00550E18(this,0,~0U,s,func_004A8368(s));}
 String(const String &s){dat=grab(s.rep());}
 String &operator=(const String &s){if(&s!=this){release(rep());dat=grab(s.rep());}return *this;}
 ~String(){release(rep());}
};
struct Self{char pad[0x54];String name;};
extern "C" void func_0056A0B8(Self *s,const char *text){s->name=String(text);}

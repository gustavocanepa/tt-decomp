/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
extern char D_00601370[];
struct String3;
extern "C" void func_005685F0(String3 *str, u32 len, s32 force);
extern "C" String3 *func_005683E0(String3 *str, u32 pos, u32 n1, u32 n2, char c);

struct String3 {
    struct Rep {
        u32 len, res, ref, selfish;
        char *data() { return (char *)(this + 1); }
        char &operator[](u32 s) { return data()[s]; }
    };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    void alloc(u32 size, s32 save) { func_005685F0(this, size, save); }
    void unique() { if (rep()->ref > 1) alloc(length(), 1); }
    void selfish() { unique(); rep()->selfish = 1; }
    char &operator[](u32 pos) { selfish(); return (*rep())[pos]; }
    char *ibegin() const { return &(*rep())[0]; }
    char *begin() { selfish(); return &(*this)[0]; }
    char *end() { selfish(); return &(*this)[length()]; }
    String3 &replace(u32 pos, u32 n1, u32 n2, char c) { return *func_005683E0(this, pos, n1, n2, c); }
    char *erase(char *f, char *l) {
        u32 o = f - ibegin();
        replace(o, l - f, (u32)0, (char)0);
        selfish();
        return ibegin() + o;
    }
    const char *c_str() const { if (length()==0) return D_00601370; dat[length()]=0; return dat; }
    void clear() { erase(begin(), end()); }
};

struct Parent { char pad[0x1c]; float rate; };
struct Self {
 void *owner; char p4[8]; Parent *parent; int f10; char p14[8];
 float accum; int count; void *head; int f28; int done;
 char p30[0x138]; String3 str;
};
extern "C" void func_0043C310(Self *);
extern "C" void func_0043C420(Self *,const char *);
extern "C" void func_00443ED0(void *);
extern "C" void func_0043C0D8(Self *s,float dt) {
 if(s->owner) {
  s->accum += dt*s->parent->rate;
  while(s->accum >= 1.0f) {
   s->count++;
   func_0043C310(s);
   if(s->head!=0) {
    if(s->done==0) {
     if(s->f10) {
      if(s->str.length()==0) func_0043C420(s,D_00601370);
      else { s->str.dat[s->str.length()]=0; func_0043C420(s,s->str.dat); }
      s->str.clear();
     }
    }
    s->done=1;
   } else s->done=0;
   s->accum -= 1.0f;
  }
  func_00443ED0((char *)s+0x40);
 }
}

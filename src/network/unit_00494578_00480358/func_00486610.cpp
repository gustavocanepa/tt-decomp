/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
extern u16 D_00605B98[], D_00605BA0[];
extern "C" int func_00486458(int) throw();
extern "C" int func_004864C0(int) throw();
extern "C" int func_00486538(int,int) throw();
extern "C" int func_004865D8(unsigned,unsigned) throw();
extern "C" int func_00486BA8(short*,int);
static inline void lower(int *c) { if ((unsigned)(*c-'A')<26) *c += 32; }
static inline void copy(u16 *d, const u16 *s) { while ((*d++ = *s++) != 0) ; }
static inline void copylast(const u16 *s, u16 *d) { while ((*d++ = *s++) != 0) ; }
extern "C" int func_00486610(u16 *dst, int a, int b, int c) {
 lower(&a); lower(&b); lower(&c);
 if ((unsigned)(a-'a')>=26 && (unsigned)(b-'a')>=26 && (unsigned)(c-'a')>=26) return 0;
 int x,y;
 if(c) { y=func_00486538(a,b); x=func_00486458(c); }
 else if(b) {
  if(a==b) {
   if(a=='n') { copy(dst,D_00605B98); return 1; }
   if(func_004864C0(a)<0) { *dst=0; return 0; }
   copy(dst,D_00605BA0); func_00486BA8((short*)(dst+1),b); return 1;
  }
  if(a=='n') {
   int vowel=0;
   if(b=='a'||b=='i'||b=='u'||b=='e'||b=='o'||b==a||b=='y') vowel=1;
   if(!vowel) { copy(dst,D_00605B98); func_00486BA8((short*)(dst+1),b); return 1; }
  }
  x=func_00486458(b); y=func_004864C0(a);
 } else { y=0; x=func_00486458(a); }
 if(x<0||y<0) { *dst=0; return 0; }
 int r=func_004865D8(y,x);
 if(r) { copylast((u16*)r,dst); return 1; }
 *dst=0; return r;
}

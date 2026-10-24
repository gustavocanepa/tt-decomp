/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline int plzcw(int x) { int r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(x)); return r; }
extern char D_0057A938[];
extern "C" int GSBuffer__getBufferWidth(void *);
extern "C" float mMoviePS2__virtual_15(void) {
 unsigned int n=GSBuffer__getBufferWidth(D_0057A938);
 int shift=(plzcw(n-1)&0x1F)^0x1F;
 return (float)n/(float)(unsigned int)(1<<shift);
}

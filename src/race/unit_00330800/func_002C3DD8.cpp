/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Img { int alloc; u8 *begin,*end,*cap; int w,h,c,d,e;
 int pitch() const { return w*e; }
 u8 *image(int x,int y) { int n=pitch()*h; return begin+n*(y*c+x); }
};
static inline u8 *row(u8 *base,int y,int pitch){ return base+y*pitch; }
static inline void swap(u8 &a,u8 &b){u8 t=a;a=b;b=t;}
extern "C" void func_002C3DD8(Img *self,int z,int slice){
 int widthbytes=self->pitch();
 int channels=self->e;
 for(int y=0;y<self->h;y++){
  int right=self->w-1;
  int x=0;
  u8 *left=row(self->image(z,slice),y,widthbytes);
  u8 *end=left+widthbytes-channels;
  for(;x<right;x++,right--){
   for(int c=0;c<channels;c++) swap(*left++,*end++);
   end-=channels*2;
  }
 }
}

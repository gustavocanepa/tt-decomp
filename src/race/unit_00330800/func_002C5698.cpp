/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
union Word { int n; u8 b[4]; };
struct Image { int p0; char *data; int p8,pc; Word w; int h; Word count; int p1c,bpp,p24; Word depth; };
struct Name { int a; u16 b; };
struct Header { short magic; u8 storage,bpc; u16 dim,x,y,z; int min,max,dummy; Name name; char rest[480]; };
extern Name D_005F2528;
extern "C" void *func_004F6678(void*,int,unsigned int);
extern "C" int func_004FF970(const char*,int,...);
extern "C" int func_004FFC00(unsigned int);
extern "C" int func_00500228(int,void*,unsigned int);
extern "C" void func_002C5610(int,int,void*,int) throw();
extern "C" void func_002C52C0(int,void*,unsigned int) throw();
static inline int swap16(u16 x) { return ((x & 255) << 8) | (x >> 8); }
extern "C" int func_002C5698(Image *p,const char *path) {
 Header h;
 func_004F6678(&h,0,512);
 h.magic=swap16(0x01da);
 h.storage=0;
 h.bpc=1;
 h.dim=0x300;
 h.x=(p->w.b[1] | (p->w.b[0]<<8));
 h.y=(p->depth.b[1] | (p->depth.b[0]<<8));
 h.z=(p->count.b[1] | (p->count.b[0]<<8));
 h.min=0;
 h.max=0xff000000;
 h.name.a=D_005F2528.a;
 h.name.b=D_005F2528.b;
 int fd=func_004FF970(path,0x602);
 if(fd<0) return 0;
 int pad=(p->depth.n-p->h)/2*p->w.n;
 func_00500228(fd,&h,512);
 for(int i=0;i<p->count.n;i++) {
  func_002C5610(fd,pad,&h,512);
  int size=p->w.n*p->bpp; size*=p->h;
  func_002C52C0(fd,p->data+size*i,size);
  func_002C5610(fd,pad,&h,512);
 }
 func_004FFC00(fd);
 return 1;
}

extern char *D_0059834C;
extern "C" void func_004A4D68(char *);
extern "C" void func_004A4DD8(char *);
extern "C" int func_004B80F8(int) throw();
extern "C" int func_004B8630(int,int) throw() __attribute__((const));
extern "C" void func_004B75D8(char *,int,int) throw();
extern "C" int func_004CB740(int,int,char *,int);
extern "C" int func_004CB8F8(int,int,int);
extern "C" int func_004CB7D8(int,void *,int);
extern "C" int func_004CB210(int);
extern "C" int func_004B9420(int id,char *name,void *buf,int off,int size) {
 int error=1;
 func_004A4D68(D_0059834C+0x34);
 int result=-1;
 if(func_004B80F8(id)) {
  int negative;
  int r=func_004CB740(id/4,id%4,name,1);
  if(id<0) negative=1; else negative=0;
  error=10;
  int fd=r;
  if(r>=0) {
   error=13;
   if(off==0 || (r=func_004CB8F8(fd,off,0))==off) {
    error=11;
    r=func_004CB7D8(fd,buf,size);
    if(r>=0) {
     result=r;
     r=func_004CB210(fd);
     error=(r==0)?0:4;
    }
   }
  }
  error=func_004B8630(error,r);
  int q=id;
  if(negative) q=(id+3);
  q >>= 2;
  int offset=(q*111+(id-q*4)*27)*4;
  func_004B75D8((char *)(offset+(int)D_0059834C+0x78),r,error);
  offset+=(int)D_0059834C;
  *(char *)(offset+0x78)=0;
 }
 int offset=((id/4)*111+(id%4)*27)*4;
 *(int *)(offset+(int)D_0059834C+0xc0)=result;
 func_004A4DD8(D_0059834C+0x34);
 return error==0 ? result : -error;
}

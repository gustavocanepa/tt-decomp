struct Buffer { int pad; char *begin; };
typedef void *(*Copy)(void*,const void*,unsigned int);
extern "C" void func_002C5DB8(char *data,int width,int height,int count,int limit,Buffer *buf,Copy copy) {
 int offset=0;
 if(width<limit) limit=width;
 int stride=width*height;
 if(width>0) do {
  int n=width-offset;
  if(limit<n) n=limit;
  char *base=buf->begin;
  char *out=base;
  if(height>0) {
   int start=offset;
   int rows=height;
   do {
    char *in=data+start;
    if(count>0) {
     int i=count;
     do {
      char *src=in;
      copy(out,src,n);
      --i;
      in+=stride;
      out+=n;
     } while(i!=0);
    }
    --rows;
    start+=width;
   } while(rows!=0);
   base=buf->begin;
  }
  char * out_2 = base;
  int total=height*count;
  char *dst=data+offset;
  if(total>0) {
   int i=total;
   do {
    --i;
    copy(dst,out_2,n);
    dst+=width;
    out_2+=n;
   } while(i!=0);
  }
  offset+=limit;
 } while(offset<width);
}

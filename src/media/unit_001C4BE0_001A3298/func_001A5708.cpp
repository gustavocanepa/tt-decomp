/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001A56D0(signed char *,unsigned char *,unsigned char *,int,int,int,int) throw();
extern "C" void func_001A5708(signed char *dst,unsigned char *a,unsigned char *b,int n,int width,int weight) {
 int inv=256-weight;
 int step=((width-1)<<16)/n;
 int pos=0;
 for(int i=0;i<n;i++) {
  int frac=(pos>>8)&255;
  int v3=frac*inv;
  int w3=frac*weight;
  frac=256-frac;
  int w0=frac*weight;
  int v0=frac*inv;
  unsigned char *pa=a+(pos>>16)*3;
  unsigned char *pb=b+(pos>>16)*3;
  func_001A56D0(dst++,pa,pb,w0,w3,v0,v3);
  func_001A56D0(dst++,pa+1,pb+1,w0,w3,v0,v3);
  func_001A56D0(dst++,pa+2,pb+2,w0,w3,v0,v3);
  pos+=step;
 }
}

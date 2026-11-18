/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Table { int data; int count; int pad[2]; };
struct Entry { char pad[16]; short id; };
extern "C" int func_004389E0(void *,unsigned);
extern "C" void *func_004368A8(Table *,void *,int);
extern "C" Entry *func_00436968(Table *,int);
extern "C" float func_00436A68(void *,float,float,float,int *,int *);
extern "C" int func_00436DA8(void **s,int *out,float *height,float x,float y) {
 int id[4]; Table table; int miss[4];
 int n=func_004389E0(s,6);
 if(n==-1) return 0;
 func_004368A8(&table,s,n);
 for(int i=table.count-1;i>=0;i--) {
  id[0]=func_00436968(&table,i)->id;
  float h=func_00436A68(*s,x,y,100.0f,id,miss);
  if(miss[0]==0) { *height=h; *out=id[0]; return 1; }
 }
 return 0;
}

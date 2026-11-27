/* compiler: ee-gcc2.9-991111 */
struct Ops { char pad[36]; int (*seek)(int,int,int); int (*sync)(int,int,int *); int (*error)(int,int); };
extern struct Ops D_00782940;
int __attribute__((register_precision ($16, 128))) func_004D8C10(int unused,int a,int b,int c) {
 int result, r;
 do { result = D_00782940.seek(a,b,c); } while (result < 0);
 D_00782940.sync(0,0,&result);
 r = result;
 if (result < 0) { result = D_00782940.error(4,result); return result; }
 return r;
}

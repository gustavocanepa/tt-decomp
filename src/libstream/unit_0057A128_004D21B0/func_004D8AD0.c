/* compiler: ee-gcc2.9-991111 */
struct Ops {
 char pad[28];
 int (*func_005AE388)(int);
 int (*unused)(void);
 int (*seek)(int,int,int);
 int (*sync)(int,int,int *);
 int (*error)(int,int);
};
extern struct Ops D_00782940;
int __attribute__((register_precision ($16, 128))) func_004D8AD0(int unused, int fd) {
 int result, r;
 do { result = D_00782940.func_005AE388(fd); } while (result < 0);
 D_00782940.sync(0,0,&result);
 r = 0;
 if (result < 0) { result = D_00782940.error(3,result); return result; }
 return r;
}

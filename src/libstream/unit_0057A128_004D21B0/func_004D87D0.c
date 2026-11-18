/* compiler: ee-gcc2.9-991111 */
int func_004FFD78(int,int,int);
int func_00505B78(void *,int);
int __attribute__((register_precision ($16, 128))) func_004D87D0(int unused, int fd) {
 int size = func_004FFD78(fd,0,2);
 if (size < 0) return func_00505B78(0,size);
 func_004FFD78(fd,0,0);
 return size;
}

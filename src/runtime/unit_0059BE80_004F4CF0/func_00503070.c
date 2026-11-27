/* compiler: ee-gcc2.9-991111 */
struct Buf { int size,result; char name[252]; char args[252]; };
extern struct Buf D_0078F500;
extern int D_0078F700;
int func_00502898(void),func_00502998(void);
char *func_004F8588(char *,const char *,unsigned int);
void *func_004F64C4(void *,const void *,unsigned int);
int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
int func_00503070(const char *name,int arglen,const void *args,int *result,int fno) {
    if(func_00502898()<0) return -0x10000;
    if(func_00502998()) return -0x10004;
    func_004F8588(D_0078F500.name,name,252);
    D_0078F500.name[251]=0;
    if(args) {
        if(arglen>252) {
            __builtin_memcpy(D_0078F500.args,args,252);
            D_0078F500.size=252;
        } else {
            func_004F64C4(D_0078F500.args,args,arglen);
            D_0078F500.size=arglen;
        }
    } else {
        D_0078F500.args[0]=0;
        D_0078F500.size=0;
    }
    if(func_004FE530(&D_0078F700,fno,0,&D_0078F500,512,&D_0078F500,8,0,0)<0) return -0x10001;
    { int ret=D_0078F500.size;
    *result=D_0078F500.result;
    return ret; }
}

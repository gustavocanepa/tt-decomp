/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0059834C;
extern "C" int func_004B80F8(int) throw();
extern "C" int func_004B8630(int,int) throw() __attribute__((const));
extern "C" void func_004B75D8(char *,int,int) throw();
extern "C" int func_004CB980(int,int,int,int,int);
extern "C" void func_004A4D68(char *);
extern "C" void func_004A4DD8(char *);
extern "C" int func_004B9778(int id,int a,int b,int c) {
    int status=1;
    func_004A4D68(D_0059834C+0x34);
    if (func_004B80F8(id)) {
        int q=id/4;
        int r=id%4;
        status=7;
        int result=func_004CB980(q,r,a,b,c);
        if(result>=0) status=0;
        status=func_004B8630(status,result);
        int offset=(q*111+r*27)*4;
        func_004B75D8((char *)(offset+(int)D_0059834C)+0x78,result,status);
        *(int *)((char *)(offset+(int)D_0059834C)+0xcc)=1;
        *((char *)(offset+(int)D_0059834C)+0x78)=0;
    }
    func_004A4DD8(D_0059834C+0x34);
    return status;
}

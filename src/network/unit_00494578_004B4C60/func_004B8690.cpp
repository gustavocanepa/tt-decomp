/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char *D_0059834C;
extern "C" int func_004B80F8() throw();
extern "C" int func_004B8630(int,int) throw() __attribute__((const));
extern "C" void func_004B75D8(char *,int,int) throw();
extern "C" int func_004CB740(int,int,int,int);
extern "C" int func_004CBB00(int,int,int);
extern "C" int func_004CB210(int);
extern "C" int func_004B8690(int id,int a,int b,int c) {
    int status=1;
    if (func_004B80F8()) {
        status=5;
        int result=func_004CB740(id/4,id%4,a,0x702);
        int handle=result;
        if (result>=0) {
            status=15;
            result=func_004CBB00(handle,b,c);
            if (result>=0) {
                status=4;
                result=func_004CB210(handle);
                if (result==0) status=0;
            }
        }
        status=func_004B8630(status,result);
        int q2=id/4;
        int offset=(q2*111+(id-q2*4)*27)*4;
        func_004B75D8((char *)(offset+(int)D_0059834C)+0x78,result,status);
        *(int *)((char *)(offset+(int)D_0059834C)+0xcc)=1;
        *((char *)(offset+(int)D_0059834C)+0x78)=0;
    }
    return status;
}

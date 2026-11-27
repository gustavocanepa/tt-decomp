/* compiler: ee-gcc2.9-991111 */
struct TopRequest {
    unsigned char mode;
    unsigned char data;
};

struct TopArg {
    int requestOut;
    int requestIn;
    struct TopRequest request[512];
};

extern int D_0078B920;
extern char D_00617670[]; /* "## internel error in libkernl.a!\n" */

int func_004FA860(int sema);
int func_004FA6D0(int thread);
int func_004FA750(int thread);
int func_004FA790(int thread);
void func_004FD350(const char *fmt, ...);

/* topThread (thread.o): serves the thread requests queued from interrupt handlers. */
void func_004FB520(struct TopArg *arg)
{
    int index;

    while (1) {
        func_004FA860(D_0078B920);
        index = arg->requestOut & 0x1FF;
        arg->requestOut = index + 1;
        switch (arg->request[index].mode) {
        case 0:
            func_004FA750(arg->request[index].data);
            break;
        case 1:
            func_004FA6D0(arg->request[index].data);
            break;
        case 2:
            func_004FA790(arg->request[index].data);
            break;
        default:
            func_004FD350(D_00617670);
            break;
        }
    }
}

/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;

typedef struct {
    unsigned int word;
    u8 flags;
} Status;

extern u8 D_005A0BCB;

int func_004DA960(void);
void func_004FA8D0(Status *st);
int func_004FAB30(u8 *p, int a, int b);

int func_004DAAF0(void)
{
    Status st;
    int ret;

    if (func_004DA960()) {
        ret = D_005A0BCB;
    } else {
        func_004FA8D0(&st);
        if (((st.word >> 13) & 7) == 0) {
            ret = 0;
        } else {
            func_004FAB30(&st.flags, 1, 1);
            ret = st.flags >> 6;
        }
    }
    return ret;
}

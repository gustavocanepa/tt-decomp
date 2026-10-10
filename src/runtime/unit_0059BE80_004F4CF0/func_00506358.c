/* compiler: ee-gcc2.9-991111 */
typedef void (*Handler)(void);
extern Handler D_005A4470;
void func_00506880(void);
int func_004FA4D0(int code, void (*handler)(void));

Handler func_00506358(Handler h)
{
    D_005A4470 = h;
    func_004FA4D0(1, func_00506880);
    func_004FA4D0(2, func_00506880);
    func_004FA4D0(3, func_00506880);
    return h;
}

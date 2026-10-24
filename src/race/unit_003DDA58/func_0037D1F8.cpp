#include "types.h"

struct func_0042F440_arg0 { s32 v; };

extern "C" char D_00768DF0[];
extern "C" char D_00768DF8[];
extern "C" char D_00768E00[];
extern "C" char D_00768E08[];

extern "C" char D_005846A0[];
extern "C" char D_005846A8[];
extern "C" char D_005846C0[];
extern "C" char D_005846C8[];
extern "C" char D_005846D8[];
extern "C" char D_005846E0[];
extern "C" char D_005846F0[];
extern "C" char D_005846F8[];

extern "C" char D_005F7260[];
extern "C" char D_005F7270[];
extern "C" char D_005F7280[];
extern "C" char D_005F7290[];

extern "C" void func_0037CAC8(void **arg0);
extern "C" void func_0037CAF8(void *arg0, int arg1) throw();
extern "C" void func_0037CD10(void **arg0);
extern "C" void func_0037CD40(void *arg0, int arg1) throw();
extern "C" void func_0037CFD8(void **arg0);
extern "C" void func_0037D008(void *arg0, int arg1) throw();
extern "C" void func_0037D148(void **arg0);
extern "C" void func_0037D178(void *arg0, int arg1) throw();
extern "C" void func_0042F440(struct func_0042F440_arg0 *arg0, void *arg1, void *arg2);
extern "C" void func_0042F460(int arg0, int arg1);

extern "C" void func_0037D1F8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0037CAC8((void **)D_00768DF0);
    if (prio == 0xFFFF && init == 1)
        func_0042F440((struct func_0042F440_arg0 *)D_005846A8, D_005F7260, D_005846A0);
    if (prio == 0xFFFF && init == 1) func_0037CD10((void **)D_00768DF8);
    if (prio == 0xFFFF && init == 1)
        func_0042F440((struct func_0042F440_arg0 *)D_005846C8, D_005F7270, D_005846C0);
    if (prio == 0xFFFF && init == 1) func_0037CFD8((void **)D_00768E00);
    if (prio == 0xFFFF && init == 1)
        func_0042F440((struct func_0042F440_arg0 *)D_005846E0, D_005F7280, D_005846D8);
    if (prio == 0xFFFF && init == 1) func_0037D148((void **)D_00768E08);
    if (prio == 0xFFFF && init == 1)
        func_0042F440((struct func_0042F440_arg0 *)D_005846F8, D_005F7290, D_005846F0);
    if (prio == 0xFFFF && init == 0) func_0042F460((int)D_005846F8, 2);
    if (prio == 0xFFFF && init == 0) func_0037D178(D_00768E08, 2);
    if (prio == 0xFFFF && init == 0) func_0042F460((int)D_005846E0, 2);
    if (prio == 0xFFFF && init == 0) func_0037D008(D_00768E00, 2);
    if (prio == 0xFFFF && init == 0) func_0042F460((int)D_005846C8, 2);
    if (prio == 0xFFFF && init == 0) func_0037CD40(D_00768DF8, 2);
    if (prio == 0xFFFF && init == 0) func_0042F460((int)D_005846A8, 2);
    if (prio == 0xFFFF && init == 0) func_0037CAF8(D_00768DF0, 2);
}

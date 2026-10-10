extern const char D_00601230[], D_00601238[], D_00601240[], D_00601248[], D_00601250[], D_00601258[], D_00601260[], D_00601268[];
struct func_00439200_Obj { int pad; int k; };
extern "C" const char *func_00439200(func_00439200_Obj *p) {
    switch (p->k) {
    case 0: return D_00601230;
    case 1: return D_00601238;
    case 2: return D_00601240;
    case 3: return D_00601248;
    case 5: return D_00601250;
    case 4: return D_00601258;
    case 6: return D_00601260;
    default: return D_00601268;
    }
}

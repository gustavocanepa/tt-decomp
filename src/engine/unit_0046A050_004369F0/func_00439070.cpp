/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { int k; int v; };
struct Tbl { Ent e[13]; };
extern char D_006011B0[];
extern "C" int func_00438F48(int) throw() __attribute__((const));
extern "C" void func_00438F50(int, int) throw();

extern "C" void func_00439070(int self, int key) {
    Tbl local = *(Tbl *)D_006011B0;
    int r = func_00438F48(self);
    for (int i=0;i<12;i++) {
        int k=local.e[i].k;
        if(k == -1) break;
        if(k == key) { r=local.e[i].v; break; }
    }
    func_00438F50(self, r);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void (*fn)(void *, int); };
struct V { Entry *vt; int x[2]; };
struct H { int x[2]; };
struct Node { Node *next; H *value; };
extern char D_00598640[], D_00598480[], D_005984F0[], D_00598428[], D_00598438[];
extern char D_005A0868[];
extern V D_00598658[2];
extern int D_00598650[2];
extern H D_00776D60[2];
extern Node D_00776D70[2];
extern Node *D_005DB0F8;
extern "C" void func_004CA680(void *, void *, void *, void *, void *);
extern "C" int func_004CAC08(V *, void *, void *);
extern "C" void func_004C9E18(H *, int, V *);
extern "C" void func_004C9E28(H *, int);
extern "C" void func_004CA6F0(void *, int);
static inline void reg(Node *self, H *v) { self->next = D_005DB0F8; self->value = v; D_005DB0F8 = self; }
extern "C" void func_004BE650(int init, int prio) {
 if (prio == 65535 && init == 1) func_004CA680(D_00598640,D_00598480,D_005984F0,D_00598428,D_00598438);
 if (prio == 65535 && init == 1) {
  func_004CAC08(D_00598658,D_005A0868,D_00598640);
  func_004CAC08(D_00598658+1,D_005A0868+20,D_00598640);
 }
 if (prio == 65535 && init == 1) {
  func_004C9E18(D_00776D60,D_00598650[0],D_00598658);
  func_004C9E18(D_00776D60+1,D_00598650[1],D_00598658+1);
 }
 if (prio == 65535 && init == 1) {
  Node *nodes = D_00776D70;
  Node *n = nodes;
  reg(n, &D_00776D60[0]);
  n++;
  reg(n, &D_00776D60[1]);
 }
 if (prio == 65535 && init == 0) {
  if (D_00776D60) { H *q=D_00776D60+2; while (q!=D_00776D60) { --q; func_004C9E28(q,2); } }
 }
 if (prio == 65535 && init == 0) {
  if (D_00598658) { V *q=D_00598658+2; while (q!=D_00598658) { --q; Entry *e=q->vt+1; e->fn((char *)q+e->delta,2); } }
 }
 if (prio == 65535 && init == 0) func_004CA6F0(D_00598640,2);
}

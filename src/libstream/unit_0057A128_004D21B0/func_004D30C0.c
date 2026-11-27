/* compiler: ee-gcc2.9-991111 */
struct Node {struct Node *next;};
extern struct Node *D_0077A014;
int func_005038D8(void);
int func_00503928(void);
int func_004D3B50(struct Node *);
void func_004D3CF8(void);
int func_004D30C0(struct Node *p) {
 int intr=func_005038D8();
 struct Node *n;
 int result;
 for(n=D_0077A014;n;n=n->next) {
 if(p==n) {
 if(intr) func_00503928();
 return -1;
 }
 }
 result=func_004D3B50(p);
 if(result==0) func_004D3CF8();
 else result=0x8105000E;
 if(intr) func_00503928();
 return result;
}

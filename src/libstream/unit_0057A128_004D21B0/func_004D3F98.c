/* compiler: ee-gcc2.9-991111 */
struct Node { unsigned int next; int x,y,id; };
struct State { char pad[24]; unsigned int head; int count; volatile int serial; };
extern struct State D_0077A028;
int func_005038D8(void);
int func_00503928(void);
void func_004D3F98(struct Node *n) {
 int intr=func_005038D8();
 unsigned int *p=&D_0077A028.head;
 struct Node *cur;
 if(*p) {
  cur=(struct Node *)*p;
  while(cur && cur<n) {
   p=&cur->next;
   cur=(struct Node *)*p;
  }
 } else cur=0;
 n->next=(unsigned int)cur;
 *p=(unsigned int)n;
 { int serial=D_0077A028.serial;
 n->id=serial;
 D_0077A028.serial=serial+1; }
 D_0077A028.count++;
 if(intr) func_00503928();
}

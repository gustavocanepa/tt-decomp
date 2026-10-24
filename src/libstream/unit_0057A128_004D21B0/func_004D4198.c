/* compiler: ee-gcc2.9-991111 */
struct Node { struct Node *next; const char *name; int x,id; };
struct Root { char pad[24]; struct Node *head; };
extern int D_005A0BB0;
int func_004A8268(const char *,const char *);
struct Root *func_004D9DD8(int);
int func_005038D8(void);
int func_00503928(void);
int func_004D4198(const char *name,int *out,int max,int *total) {
 int count,intr,n;
 struct Node *p;
 if(!D_005A0BB0) return (int)0x81058001;
 count=0;
 intr=func_005038D8();
 p=func_004D9DD8(0)->head;
 n=0;
 while(p) {
  if(!name || func_004A8268(name,p->name)==0) {
   n++;
   if(count<max) { *out++=p->id; count++; }
  }
  p=p->next;
 }
 if(intr) func_00503928();
 if(total) *total=n;
 return count;
}

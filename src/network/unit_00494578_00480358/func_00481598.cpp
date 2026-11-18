/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x30]; void (*handler)(Obj *); int handlerArg; };
struct Node { Obj *object; Node *prev; Node *next; };
struct List { Node *head; Node *tail; };
struct Pool { char pad[0x10]; char mutex[0x98]; List list; };
extern Pool D_00773880;
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004AC8B8(List *, Node *);
extern "C" void func_00481508(Obj *) throw();
extern "C" void func_00481690(Obj *);
static inline Obj *pop(List *list) {
 Obj *result=0;
 Node *node=list->head;
 if(node) {
  func_004AC8B8(list,node);
  result=node->object;
 }
 return result;
}
static inline Obj *allocate(Pool *pool) {
 func_004A4D68(pool->mutex);
 Obj *result=pop(&pool->list);
 func_004A4DD8(pool->mutex);
 return result;
}
extern "C" Obj *func_00481598() {
 Obj *result=allocate(&D_00773880);
 if(result) {
  func_00481508(result);
  result->handlerArg=0;
  result->handler=func_00481690;
 }
 return result;
}

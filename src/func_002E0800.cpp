/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *parent; };
extern "C" int parentContains(Node *, Node *) __asm__("func_002E0800");
extern "C" int func_002E0800(Node *node, Node *target) {
 int result = 1;
 if (target != node) {
  Node *parent = node->parent;
  if (parent != 0) return parentContains(parent, target);
  result = 0;
 }
 return result;
}

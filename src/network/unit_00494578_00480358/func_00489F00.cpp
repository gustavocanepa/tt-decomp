/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
/* Reads from an func_005AE360 file under the owner's lock: looks the handle up in the map (-9 if unknown),
   clamps len to what is left of the payload after the current position and hands the func_005AE2E8 to
   func_004893D8; the same map/guard shapes as the seek func_004CD0F0. */
struct Block { int a,b,c,d; };
struct __attribute__((packed)) Header { char pad[28]; unsigned size; };
struct Data { int active; void *buf; Header *payload; int file; unsigned pos; Block block; };
struct Value { const unsigned first; Data *second; };
struct NodeBase { int color; NodeBase *parent,*left,*right; };
struct Node : NodeBase { Value value; };
struct IteratorBase { NodeBase *node; };
template <class Ref,class Ptr> struct Iter : IteratorBase {
 typedef Iter<Value&,Value*> iterator;
 Iter() {}
 Iter(Node *p) { node=p; }
 Iter(const iterator &it) { node=it.node; }
 Ref operator*() const { return ((Node*)node)->value; }
 Ptr operator->() const { return &(operator*()); }
};
inline bool operator==(const IteratorBase &a,const IteratorBase &b) { return a.node==b.node; }
struct Tree;
extern "C" Iter<Value&,Value*> func_0056FA40(Tree*,const unsigned&);
struct Tree {
 int allocator; Node *header; unsigned count; int compare;
 typedef Iter<Value&,Value*> iterator;
 iterator find(const unsigned &key) { return func_0056FA40(this,key); }
 iterator end() { return header; }
};
struct Map {
 Tree t;
 typedef Iter<Value&,Value*> iterator;
 typedef Iter<const Value&,const Value*> const_iterator;
 iterator find(const unsigned &key) { return t.find(key); }
 iterator end() { return t.end(); }
};
extern "C" int func_004893D8(void*,Data*,void*,unsigned,int);
extern "C" void func_004A4D68(void*);
extern "C" void func_004A4DD8(void*);
struct Guard {
 void *p;
 Guard(void *v):p(v) {func_004A4D68(p);}
 ~Guard() {func_004A4DD8(p);}
};
struct Owner { void *vtable; void *list; Map map; int unused; char mutex[48]; };
extern "C" int func_00489F00(Owner *s,int key,void *buf,unsigned len) {
 Guard guard(s->mutex);
 Map::const_iterator it=s->map.find(key);
 if(it==s->map.end()) return -9;
 Data *data=it->second;
 unsigned size=data->payload->size;
 if(size<data->pos+len) len=size-data->pos;
 if(len==0) return 0;
 return func_004893D8(s,data,buf,len,1);
}

struct Value{char pad[1491];signed char id;};struct Entry{char pad[24];Value*value;};struct List{int count;int unused;Entry**items;};struct Owner{char pad[96];List*list;};struct S{int unused;Owner*owner;};
extern "C" int func_003542A0(S*s,int id){List*l=s->owner->list;int count=l->count;for(int i=0;i<count;i++){if(l->items[i]->value->id==id)return i;}return -1;}

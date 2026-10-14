struct S{char p[16];void*owner;char q[0x38];int a,b,c,result;char r[0x48];unsigned flags;};
extern "C" int func_002E42C8(void*,int,int,int);
extern "C" void func_002D8B18(S*self){int a=func_002E42C8(self->owner,7,0,0);int b=func_002E42C8(self->owner,8,0,0);int c=func_002E42C8(self->owner,9,0,0);int da=a!=self->a;int db=b!=self->b;int dc=c!=self->c;int changed=da;changed|=db;changed|=dc;if(changed){if(dc&&c)self->result=6;else if(db&&b)self->result=5;else self->result=a;self->a=a;self->b=b;self->c=c;self->flags=(self->flags&0xffff00ffu)|0x100;}}

/* compiler: ee-gcc2.9-991111 */
struct Queue { char pad[12]; unsigned char *func_005AE268; };
struct Tty { int socket; volatile int wlen,rlen; volatile int busy; unsigned char *wbuf,*rbuf; struct Queue *queue; };
extern void func_004FBB28(struct Queue *);
extern void func_004FD350(const char *,...);
extern int func_00505CF0(int,void *,int);
extern int func_00505D28(int,void *,int);
extern char D_006176C8[],D_006176F0[],D_00617708[],D_00617720[];
void func_004FBBA8(int event,int count,struct Tty *t) {
 unsigned short *packet;
 switch(event) {
 case 1: case 2:
  if(count!=0) {
   int offset;
   if((unsigned)(t->rlen+count)>0x140) func_004FD350(D_006176C8);
   offset=t->rlen;
   count=func_00505CF0(t->socket,t->rbuf+offset,count & 0xffff);
   if(count<0) func_004FD350(D_006176F0);
   t->rlen+=count;
  } else {
   packet=(unsigned short *)t->rbuf;
   for(count=12;count<*packet;count++) {
    *t->queue->func_005AE268=t->rbuf[count];
    func_004FBB28(t->queue);
   }
   t->rlen=0;

  }
  return;
 case 3: {
  int n=func_00505D28(t->socket,t->wbuf,t->wlen & 0xffff);
  if(n<0) {func_004FD350(D_00617708,n); t->busy=0;}
  else {t->wbuf+=n; t->wlen-=n;}
  return;
 }
 case 4:
  if(t->wlen!=0) func_004FD350(D_00617720,t->wlen);
  t->busy=0;
  return;
 default: break;
 }
}

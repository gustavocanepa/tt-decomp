/* compiler: ee-gcc2.9-991111 */
extern int func_00502898(void);
extern int func_004FE530(void *,int,int,void *,int,void *,int,void *,void *);
extern char D_0078F700[];
extern int D_0078F500[8];
int func_00503428(int addr, void *dst, unsigned int type) {
 if (func_00502898()<0) return 0xffff0000;
 if (type>=3) return 0xfffefffe;
 D_0078F500[0]=addr;
 D_0078F500[1]=type;
 if (func_004FE530(D_0078F700,3,0,D_0078F500,32,D_0078F500,32,0,0)<0) return 0xfffeffff;
 if (type==0) *(unsigned char *)dst=*(unsigned char *)D_0078F500;
 else if (type==1) *(unsigned short *)dst=*(unsigned short *)D_0078F500;
 else if (type==2) *(int *)dst=D_0078F500[0];
 else return 0xfffefffe;
 return 0;
}

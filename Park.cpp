#include <stdio.h>
#include <stdlib.h>
typedef struct car *Pcar;
struct car{
    int arrive,leave;
    int carNo;
};
typedef struct car *Pcar;
Pcar createCra(){
    int c,a,l;
    Pcar q=(Pcar)malloc(sizeof(struct car));
    if(q!=NULL){
        scanf("%d%d%d",&c,&a,&l);
        q->carNo=c;
        q->arrive=a;
        q->leave=l;
        return q;
    }
    printf("out of space!\n");
    return NULL;
}
typedef struct park *pPark;
struct Park{
    int max;
    int f,r;
    Pcar *ele;
};
typedef struct Park *Que_park;
Que_park createPark(int m){
    Que_park q=(Que_park)malloc(sizeof(struct Park));
    if (q!=NULL){
        q->ele=(Pcar *)malloc(sizeof(struct car)*m);
        if(q->ele!=NULL){
            q->max=m;
            q->r=q->f=0;
            return q;
        }
        else free(q);
    }
    printf("out of space!\n");
    return NULL;
}
int enCar(Que_park paqu,Pcar x){
    if((paqu->r+1)%paqu->max==paqu->f)
        printf("FULL queue.\n");
    else{
        paqu->ele[paqu->r]=x;
        paqu->r=(paqu->r+1)%paqu->max;
    }
}
Pcar frontQue(Que_park paqu){
    if(paqu->f==paqu->r) printf("empty queue!\n");
    else{
        return (paqu->ele[paqu->f]);
    }
}
void deque(Que_park paqu){
    if(paqu->f==paqu->r) printf("empty queue!\n");
    else paqu->f=(paqu->f-1)%paqu->max;
}

//栈
struct stack{
    int max;
    int t;
    Pcar *s;
};
typedef struct stack *pstack;
pstack createStcak(int m){
    pstack q=(pstack)malloc(sizeof(struct stack));
    if(q!=NULL){
        q->s=(Pcar *)malloc(sizeof(struct car)*m);
        if(q->s!=NULL){
            q->t=-1;
            q->max=m;
            return q;
        }
        else printf("faild!\n");
    }
    return NULL;
}

int isEmptyStack(pstack st){ //判断栈是否为空
    return st->t==-1;
}

void push(pstack st,Pcar c){
    if(st->t>=st->max) printf("OVERflow stack!\n");
    else {
        st->t=st->t+1;
        st->s[st->t]=c;
      //  printf("在停车场%d号位置\n",st->t);
    }
}
void pop(pstack st){
    if(isEmptyStack(st)) printf("is empty stack!\n");
    else st->t=st->t-1;
}
Pcar top(pstack st){
    if(isEmptyStack(st)) printf("is empty stack\n");
    else return (st->s[st->t]);
}

void arrivr(int time,int carno,pstack st,Que_park pa){
    Pcar c=(Pcar)malloc(sizeof(struct car));
    if(c!=NULL){
        c->carNo=carno;
        c->arrive=time;
        if(st->t<st->max){
            push(st,c);
            printf("在停车场%d号位置\n",st->t);
        }
        else{
            enCar(pa,c);
            printf("在便道%d号位置\n",pa->r);
        }
    }
    else printf("失败\n");
}
void leave(int time,int carno,pstack st,Que_park pa){
    int lt;
    if(pa->r!=pa->f){
        Pcar q=frontQue(pa);
        lt=time-q->arrive;
        int price=lt*5;
        printf("车牌号为%d的车在便道的停留时间为%d,费用为0元.\n",carno,lt);
        deque(pa);
    }
    else if(st->t>=0){
        Pcar q=top(st);
        lt=time-q->arrive;
        int price=lt*5;
        printf("车牌号为%d的车停车场停留时间为%d,费用为%d元.\n",carno,lt,price);
        pop(st);
    }
    else
        printf("停车场和便道不存在车！\n");
}
int main()
{
    pstack s=createStcak(3);
    Que_park park=createPark(20);
   // if(isEmptyStack(s)) printf("null\n");
   // Pcar car=createCra();
   // Pcar car2=createCra();
   // enCar(park,car);
  //  push(s,car2);
   // Pcar car3=top(s);
   // Pcar car1=frontQue(park);
    //printf("Hello world!\n");
  //  printf("车牌号：%d  到达时间：%d  离开时间：%d\n",car1->carNo,car1->arrive,car1->leave);
   // printf("车牌号：%d  到达时间：%d  离开时间：%d\n",car3->carNo,car3->arrive,car3->leave);*/
    int time,carno;
    char x;
    char s1='a',s2='l';
    while(1){
    printf("输入a/l,a/l的时间,车牌号！\n");
    scanf("%c%d%d",&x,&time,&carno);

    if(x==s1){
       //printf("a\n");
        arrivr(time,carno,s,park);
    }
    else if(s2==x){
       // printf("L\n");
        leave(time,carno,s,park);
    }
    }
    //else
    return 0;
}

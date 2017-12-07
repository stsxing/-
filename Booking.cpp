#include <stdio.h>
#include <stdlib.h>
struct people{
    char name;
    int grade;
};
typedef struct people *ppeople;
typedef struct fly *pfly;
struct fly{
    int fno;
    char sta,des;
    int statime,destime;
    int count;
    int x;
    ppeople pe[100];
    pfly link;

};
typedef struct fly *Linklist;
struct queue{
    int max;
    int f,r;
    ppeople *q;
};
typedef struct queue *pqueue;
pqueue createqueue(int m){
    pqueue q=(pqueue)malloc(sizeof(struct queue));
    if(q!=NULL){
        q->q=(ppeople*)malloc(sizeof (struct people)*m );
        q->max=m;
        q->r=q->f=0;
        return q;
    }
    printf("out of space!\n");
    return NULL;
}
int isnullqueue(pqueue paqu){
    if(paqu->r==paqu->f) return 1;
    else return 0;
}
void enqueuepeople(pqueue paqu,ppeople po){
    if((paqu->r+1)%paqu->max==paqu->f) printf("full queue\n");
    else{
        paqu->q[paqu->r]=po;
        paqu->r=(paqu->r+1)%paqu->max;
    }
}
ppeople frontqueue(pqueue paqu){
    if((paqu->r+1)%paqu->max==paqu->f) printf("full queue\n");
    else return(paqu->q[paqu->f]);
}
void dequepeople(pqueue paqu){
    if(paqu->f==paqu->r) printf("empty queue!\n");
    else paqu->f=(paqu->f+1)%paqu->max;
}

int isNULL(Linklist llist){
    return llist->link==NULL;
}
Linklist createhearNode(){
    Linklist p=(Linklist)malloc(sizeof(struct fly));
    if(p!=NULL){
        p->link==NULL;
        return p;
    }
    else{
        printf("create herd Node faild!");
    }
    return NULL;
}

int chushihua(Linklist llist){
    int i;
    Linklist p=llist;
    Linklist q=(Linklist)malloc(sizeof(struct fly));
    q->link=NULL;
    q->fno=01;
    q->count=2;
    q->sta='s';
    q->des='d';
    q->statime=11101245;
    q->destime=11100210;
    q->x=3;
    for(i=0;i<q->count;i++) q->pe[i]=NULL;
    p->link=q;

    Linklist q1=(Linklist)malloc(sizeof(struct fly));
    q1->link=NULL;
    q1->fno=02;
    q1->count=20;
    q1->sta='q';
    q1->des='w';
    q1->statime=10101230;
    q1->destime=10100230;
    q1->x=5;
    for(i=0;i<q1->count;i++) q1->pe[i]=NULL;
    q->link=q1;
    return 0;

}
int buyticket(Linklist llist){
    int i;
    Linklist p=llist;
    ppeople q=(ppeople)malloc(sizeof(struct people));
    if(q!=0){
        printf("输入购票人姓名！\n");
        char c=getchar();
        c=getchar();
        //char na;
        //scanf("%c",&na);
        q->name=c;
        for(i=0;i<20;i++){
            if(p->pe[i]==NULL){
                p->pe[i]=q;
                p->count=p->count-1;
                printf("买票成功！购买人姓名为：%c. 座位号为：%d\n",c,i);
                return 0;
            }
        }
        printf("购票失败！\n");
    }
    return 0;
}
int frontQueueBuyTicket(Linklist llist,pqueue paqu){
    int i;
    Linklist p=llist;
    ppeople po=frontqueue(paqu);
    for(i=0;i<20;i++){
        if(p->pe[i]==NULL){
            p->pe[i]=po;
            p->count--;
            dequepeople(paqu);
            printf("排队购票成功！乘机人是：%c座位号为：%d\n",po->name,i);
            return 0;
        }
    }
    printf("失败！\n");
    return 0;
}
int canceTicket(Linklist llist){
    Linklist p=llist;
    int i;
    ppeople pp;
    printf("输入退票人姓名\n");
    char c=getchar();
    c=getchar();
    printf("输入成功！\n");
    printf("输入的是%c\n",c);
    for(i=0;i<20;i++){
        pp=p->pe[i];
        printf("1\n");
        if(pp->name==c){
            p->pe[i]=NULL;
            p->count++;
            printf("退票成功！\n");
            return 0;
        }

        }
    printf("不存在这个人！\n");
    return 0;

}
int searchFly(Linklist llist,pqueue paqu){
    char c;//=getchar();
    scanf("%c",&c);
   // scanf("%c",&c);
    Linklist p=llist;
    pqueue pa=paqu;
    while(p!=NULL){
        if(c==p->des){
            printf("查找成功！\n");
            printf("航班号：%d 起飞站：%c.目的地：%c.起飞时间：%d月%d日%d点%d分. 到达时间：%d月%d日%d点%d分. 星期%d起飞.剩余票数：%d\n",
            p->fno,p->sta,p->des,p->statime/1000000,p->statime%1000000/10000,p->statime%10000/100,p->statime%100,
            p->destime/1000000,p->destime/1000000%10000,p->destime%10000/100,p->destime%100,p->x,p->count);
            int s0;
            printf("输入1买票，输入2退票！\n");
            scanf("%d",&s0);
            printf("%d\n",s0);
            if(s0==1){
                if(p->count>0){
                    printf("是否要购买该航班机票？按Y确认！其他键退出！\n");
                    //char select;
                    //select=getchar();
                   // int a;
                   // scanf("%d",&a);
                    //printf("sdsadw");
                    // scanf("%c",&select);
                    char a=getchar();
                    a=getchar();
                    if(a=='y'){
                        printf("确定买票！\n");
                        buyticket(p);
                    }
                }
                else{
                            printf("暂时无机票，是否要登记排队？按Y确定登记\n");
                            char s1=getchar();s1=getchar();
                            //printf("%c",s1);
                            if(s1=='y'){
                            printf("Y\n");
                            printf("输入乘机人姓名！\n");
                            char s2=getchar();s2=getchar();
                            ppeople po=(ppeople)malloc(sizeof(struct people));
                            po->name=s2;
                            enqueuepeople(paqu,po);
                            printf("登记成功！\n");

                        }

                }
            }
            else if(s0==2){
                    printf("确认退票！\n");
                    canceTicket(p);
                    if(paqu->r!=paqu->f){
                        printf("正在排队买票！\n");
                        frontQueueBuyTicket(p,paqu);
                }
            }
            return 0;
        }
    p=p->link;
   }
   // printf("不存在飞往该目的地的航班！\n");
    return 0;

}
int main()
{
    Linklist p1=createhearNode();
    Linklist p=p1;
    pqueue q1=createqueue(10);
    pqueue q=q1;
    chushihua(p);
    //printf("初始化成功！\n");
    while(1){
        printf("输入您的目的地！\n");
        searchFly(p,q);
    }

  //  printf("Hello world!\n");
    return 0;
}

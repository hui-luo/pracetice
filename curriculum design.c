//汽车配件仓库管理系统
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct autoparts {                       //节点定义
int number;                              //配件编号
char part_name[20];                      //配件名称
char producer[30];                       //生产者
char department[30];                     //生产部门
char result[10];                         //质检结果（合格/不合格）
char problem[30];                        //质检问题（设计缺陷/装配质量/加工质量）
char quality_inspector[30];              //质检员
char date[30];                           //质检日期
struct  autoparts *next;
} ;


struct autoparts * input();
void show_by_number(struct  autoparts *head);
void show_by_producer(struct  autoparts *head);
void modify_by_number(struct  autoparts *head);
void delete_by_number(struct  autoparts *head);
void save(struct  autoparts *head,FILE *fp);
void count(struct  autoparts *head);


int main (void)

{
    FILE * fp;
    int select;
    struct autoparts *head,*p;
    do
    {
        printf("*************************\n");
        printf("*         菜单          *\n");
        printf("*************************\n");
        printf("* 1.打开文件\n");
        printf("* 2.输入质检信息\n");
        printf("* 3.通过质检编号显示质检信息\n");
        printf("* 4.通过生产者显示质检信息\n");
        printf("* 5.指定质检编号修改信息\n");
        printf("* 6.指定质检编号删除信息\n");
        printf("* 7.统计\n");
        printf("* 8.保存并关闭文件\n");
        printf("* 0.退出\n");
        scanf("%d",&select);
        switch (select)
        {
       
        case 1: 
            if ((fp = fopen ("E:\\c\\lh.txt1","w")) == NULL)
            {
                printf("File open error");
                exit(0);
            }   
            break;
        case 2: head = input();
            break;
        case 3: show_by_number(head);
            break;
        case 4: show_by_producer(head);
            break;
        case 5:modify_by_number(head);
            break;
        case 6:delete_by_number(head);
            break;
        case 7:count(head);
            break;
        case 8:save(head,fp);
            break;
        }
    } while (select <= 8 && select >=1);
    
}
struct autoparts * input()               //输入质检信息
{
    int size = sizeof (struct autoparts);
    struct autoparts *head,*tail,*p;
    head = tail =NULL;
    int number;                              //配件编号
    char part_name[20];                      //配件名称
    char producer[30];                       //生产者
    char department[30];                     //生产部门
    char result[10];                         //质检结果（合格/不合格）
    char problem[30];                        //质检问题（设计缺陷/装配质量/加工质量）
    char quality_inspector[30];              //质检员1
    char date[30];                           //质检日期
    do
    {
        printf("配件编号为0结束\n");
        printf("配件编号：");
        scanf("%d",&number);
        if (number == 0)
        {
            break;
        }
        
        printf("配件名称：");
        scanf("%s",part_name);
        printf("生产者：");
        scanf("%s",producer);
        printf("生产部门：");
        scanf("%s",department);
        printf("质检结果(y:合格/n:不合格)：");
        scanf("%s",result);
        printf("质检问题(1:设计缺陷2:装配重量3:加工质量4：其它)：");
        scanf("%s",problem);
        printf("质检员：");
        scanf("%s",quality_inspector);
        printf("质检日期：");
        scanf("%s",date);
        p = (struct autoparts *) malloc (size);
        p->number = number;
        strcpy(p->part_name,part_name);
        strcpy(p->producer,producer);
        strcpy(p->department,department);
        strcpy(p->result,result);
        strcpy(p->problem,problem);
        strcpy(p->quality_inspector,quality_inspector);
        strcpy(p->date,date);
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            tail->next = p;
        }
        tail = p;
    } while (number != 0 );
    
    return head;
}
void show_by_number(struct autoparts *head)                  //根据质检编号显示质检信息
{
    struct autoparts *p;
    int n;
    printf("配件编号：");
    scanf("%d",&n);
    int a = 0;                                                     //判断输入的编号是否存在
    for ( p = head; p != NULL; p = p->next)
    {
        if(p->number == n)
        {
            printf("配件名称 生产者 生产部门 质检结果 质检问题 质检员 质检日期\n");
            printf("%4d%8s%10s%8s%4s%4s%8s%4s\n",p->number,p->part_name,p->producer,p->department,p->result,p->problem,p->quality_inspector,p->date);
            a = 1;
            break;
            
            
        }
        
    }
    if ( a == 0)
        {
            printf("not found");
        }
          
}
void show_by_producer(struct  autoparts *head)              //根据生产者显示质检信息
{
    struct  autoparts *p;
    char name[30];
    int a = 0;                                                   //判断生产者是否存在
    printf("生产者：");
    scanf("%s",name);
    printf("配件名称 生产者 生产部门 质检结果 质检问题 质检员 质检日期");
    for ( p = head; p != NULL; p = p->next)
    {
        if (strcmp(p->producer,name) == 0)
        {
            printf("%4d%4s%8s%10s%4s%4s%4s%8s",p->number,p->part_name,p->producer,p->department,p->result,p->problem,p->quality_inspector,p->date);
            a = 1;
        }
        
    }
    if (a == 0)
    {
        printf("not found");
    }
}
void modify_by_number(struct  autoparts *head)            //指定质检编号修改信息
{
    struct  autoparts *p;
    printf("质检编号：");
    int n;                                               //n为质检编号
    char a[30];                                          //a为修改后的信息
    scanf("%d",&n);
    int l;
    int h = 0;                                              //判断n是否存在h为判断变量
    for ( p = head ; p != NULL; p = p->next)
    {
        if (p->number == n)
        {
            h = 1;                                           //如果n存在h变为1  
        }
        
    }
    if ( h == 0 )
    {
        printf("配件不存在");
    }
    
    while( h == 1)
    {
        printf("1.配件名称 2.生产者 3.生产部门 4.质检结果 5.质检问题 6.质检员 7.质检日期 0.退出\n");
        printf("需要修改的信息：");
        scanf("%d",&l);
        if (l <= 7 && l >=1)
        {
            printf("输入修改后的信息：");
            scanf("%s",a);
            for ( p = head; p != NULL; p = p->next)
            {
                if ( p->number == n)
                {
                    switch (l)
                    {
                    case 1:strcpy(p->part_name,a);
                        break;
                    case 2:strcpy(p->producer,a);
                        break;
                    case 3:strcpy(p->department,a);
                        break;
                    case 4:strcpy(p->result,a);
                        break;
                    case 5:strcpy(p->problem,a);
                        break;
                    case 6:strcpy(p->quality_inspector,a);
                        break;
                    case 7:strcpy(p->date,a);
                        break;
                   
                    }
                }
                
            }
            
        }
        if ( l == 0 )
        {
            break;
        }
        
    }
    
   

}
void delete_by_number(struct  autoparts *head)            //指定质检编号删除信息
{
    printf("质检编号：");
    int number;
    scanf("%d",&number);
    struct autoparts *ptr1,*ptr2;
    if ( head->number == number )             //如果删除的是第一个节点
    {
       ptr2 = head;
       head = head->next;
       ptr2 = NULL;
    }
    else
    {
        
    
    
    ptr1 =head;
    ptr2 =head->next;  
    
    
    while ( ptr2 != NULL )                                      //若删除的节点不是第一个节点
    {
        if ( number == ptr2->number )
        {
            ptr1->next = ptr2->next;
            ptr2 = NULL;
        }
        else
        {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        
        
    }
    }
    
}
void count(struct  autoparts *head)                                             //统计各种配件的数量            
{
    struct autoparts *p;
    printf("配件名称：");
    char name[30];
    scanf("%s",name);
    int count=0;                                                                 //count用于计算数量
    for ( p = head; p != NULL; p = p->next)
    {
        if (strcmp(p->part_name,name) == 0)
        {
            count++;
        }
        
    }
    printf("%s数量为：%d",name,count);
}
void save(struct  autoparts *head,FILE *fp)
{
    struct autoparts *p;
    for ( p = head; p != NULL; p = p->next)
    {
        fprintf(fp,"%4d%4s%4s%4s%4s%4s%4s%4s\n",p->number,p->part_name,p->producer,p->department,p->result,p->problem,p->quality_inspector,p->date);
    }
    if (fclose(fp))
    {
        printf(" Can not close the file!\n");
    }
}
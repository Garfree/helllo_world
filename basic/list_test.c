#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
//#include <time.h>

#include "list.h"

//����app_info����ṹ
typedef struct application_info
{
    uint32_t  app_id;
    uint32_t  up_flow;
    uint32_t  down_flow;
	
	struct    list_head app_info_node;//����ڵ�
}app_info;

/* container_of */
void container(void)
{
    size_t off_set = 0;
    off_set = offsetof(app_info, app_id);
    printf("id offset: %u\n",off_set);
    off_set = offsetof(app_info, up_flow);
    printf("up_flow offset: %u\n",off_set);
    off_set = offsetof(app_info, down_flow);
    printf("down_flow offset: %u\n",off_set);
	
    app_info *stu = (app_info *)malloc(sizeof(app_info));
    
	stu->up_flow = 10;
	app_info *ptr = container_of(&(stu->up_flow), app_info, up_flow);
    printf("up_flow:%d\n", ptr->up_flow);
    printf("stu address:%p\n", stu);
    printf("ptr address:%p\n", ptr);
}

/* �ڵ�����ռ䲢��ֵ */
app_info* get_app_info(uint32_t app_id, uint32_t up_flow, uint32_t down_flow)
{
    app_info *app = (app_info*)malloc(sizeof(app_info));
    if (app == NULL)
    {
		fprintf(stderr, "Failed to malloc memory, errno:%u, reason:%s\n",
			errno, strerror(errno));
		return NULL;
    }
    app->app_id = app_id;
    app->up_flow = up_flow;
    app->down_flow = down_flow;
    return app;
}

static void for_each_app(const struct list_head *head)
{
    struct list_head *pos;
    app_info *app;
    //��������,�����Ҫɾ���ڵ����ݣ���ʹ�� list_for_each_safe
    list_for_each(pos, head)
    {
		app = list_entry(pos, app_info, app_info_node);
		printf("ap_id: %u\tup_flow: %u\tdown_flow: %u\n",
			app->app_id, app->up_flow, app->down_flow);
    }
}

/* ����������� */
static void app_list_insert(int data,app_info *app,struct list_head *head)
{
    app = get_app_info(data, 5*data, 10*data);
    list_add_tail(&app->app_info_node, head);
    printf("After insert three app_info: \n");
    for_each_app(head);
}

/* ����һ���ڵ��Ƶ�ĩβ */
static void app_list_move(struct list_head *head)
{
    printf("Move first node to tail:\n");
    list_move_tail(head->next, head);
    for_each_app(head);
}

/* ɾ�����һ���ڵ� */
static void app_list_del(struct list_head *head)
{
	if(head ==head->next)
		return;
	
	app_info *ptr = container_of(head->prev, app_info,app_info_node);
    printf("Delete the last node:\n");
    list_del(head->prev);
    for_each_app(head);
	if(ptr)
		free(ptr);
}

/* ɾ������������ */
void destroy_app_list(struct list_head *head)
{
	app_info *ptr = NULL;
    struct list_head *pos = head->next;
    struct list_head *tmp = NULL;
	
	printf("Destroy app list.\n");
    while (pos != head)
    {
		tmp = pos->next;
		ptr = container_of(pos, app_info,app_info_node);
		list_del(pos);
		if(ptr)
			free(ptr);
		pos = tmp;
    }
	/* ɾ�����ڵ㣬�ͷſռ䣬���� app_info_list ָ��û����գ������ں����ⲿɾ�����ڵ� */
	// ptr = container_of(pos, app_info,app_info_node);
	// if(ptr)
	// {
		// printf("free root node,id=%d\n",ptr->app_id);
		// free(ptr);
	// }
	
}


/*list operation test */
void list_test(void)
{
    int n,m;
	//����һ��app_info
    app_info * app_info_list = (app_info*)malloc(sizeof(app_info));
	app_info_list ->app_id =123;
    //app_info *app;
    if (app_info_list == NULL)
    {
		fprintf(stderr, "Failed to malloc memory, errno:%u, reason:%s\n",
			errno, strerror(errno));
		return;
    }
    //��ʼ������ͷ��
    struct list_head *head = &app_info_list->app_info_node;
    init_list_head(head);
	
    while(1)
    {
		m++;
        printf("\n1.container\t 2.insert\t 3.move\t 4.del\t 5.test\t \n");
        printf("Choose list test option :");
        fscanf(stdin,"%d",&n);
        switch(n)
        {
        case 1:
			container();
        break;
		case 2:
			app_list_insert(m,app_info_list,head);
        break;
		case 3:
			app_list_move(head);
        break;
		case 4:
			app_list_del(head);
        break;
        
        default:
            break;
        }
        getchar();
        if(0 == n)
            break;
    }
	destroy_app_list(head);
	if(app_info_list)
	{
		printf("free app info list,id=%d\n",app_info_list->app_id);
		free(app_info_list);
	}
}
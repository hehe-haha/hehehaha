/****************************************************************************/
/* Copyright (c) SSE@USTC, 2014-2015                                        */
/*                                                                          */
/*  FILE NAME               :    menu.c                                     */
/*  PRINCIPAL AUTHOR        :    Huangyizhe                                 */
/*  SUBSYSTEM NAME          :    menu                                       */
/*  MODULE NAME             :    menu                                       */
/*  LANGUAGE                :    C                                          */
/*  TARGET ENVIRONMENT      :    ANY                                        */
/*  DATE OF FIRST RELEASE   :    2014/09/11                                 */
/*  DESCRIPTION             :    This is a menu program                     */
/****************************************************************************/

/*
 * Revision log:
 *
 * Created by Huangyizhe, 2014/9/11
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_LEN    1024
#define CMD_LEN     128
#define CMD_NUM     10

/* data struct and its operations */

typedef struct DataNode 
{
    char    cmd[CMD_LEN];
    char    desc[DESC_LEN];
    struct  DataNode *next;
} tDataNode;

/* init a cmd list */

tDataNode * Initcmd(tDataNode *p )
{
    tDataNode *head = NULL;
    int i;
    char str[CMD_LEN] = "cmd";
    for (i = 0; i<CMD_NUM; i++)
    {
        p = (tDataNode*)malloc(sizeof(tDataNode));
        p->cmd[0] = (char) ('A'+i);
        strcat(p->cmd,str);
        snprintf(p->desc, DESC_LEN, "This is %s cmd!",p->cmd);
        p->next = head;
        head = p;
    }
    return(p);
}

/* show all cmd in the linklist */

void ShowMenulist(tDataNode *p)
{
    printf("Menu List:\n");
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
} 

/* run cmd in the linklist */

void RunCmdlist(tDataNode *p)
{
    tDataNode *q = NULL;
    while(1)
    {
        char cmd[CMD_LEN];
        printf("Input a cmd > ");
        scanf("%s", &cmd);
        q = p;
        while(q != NULL)
        {
            if(strcmp(q->cmd,cmd)==0)
            {
                printf("%s - %s\n", q->cmd, q->desc);
                break;
            }
            q = q->next;
        }
        if(q == NULL )
        {
            printf("Enter a wrong cmd!\n");
        }
    }

}

void main()
{
    tDataNode *p = NULL;
    p = Initcmd(p);
    ShowMenulist(p);
    RunCmdlist(p);
}



#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 20

void dijkstra(int Graph_Adj[MAX][MAX],int n,int startpath,int endpath,char NODE[][1000]);
int count_place=0;
int count1_place=0;
int flag=1;
int store_first,store_last;

int main()
{
    int Graph_Adj[MAX][MAX],i,j,input_vertex,u,u1,l,m,flag=0;
    char input_first[200];
    char input_second[200];

    printf("Please Enter Number of Node: ");
    scanf("%d",&input_vertex);
    char NODE[input_vertex][1000];
    printf("\n");
    for(i=0; i<input_vertex; i++)
    {
        printf("Enter The Node Name[%d]= ",i+1);
        scanf("%s",&NODE[i]);
    }

    printf("\n");

    for(i=0; i<input_vertex; i++)
    {
        for(j=0; j<input_vertex; j++)
        {
            printf("Adjacency matrix Between %s and %s :",NODE[i],NODE[j]);
            scanf("%d",&Graph_Adj[i][j]);
        }
    }

    printf("\nEnter Name Of The Starting Node: ");

    scanf("%s",&input_first);


    /* check value*/

    for(m=0; m<input_vertex; m++)
    {
        count_place++;

        if (strcmp(input_first,NODE[m]) == 0)
        {
            store_first=(count_place-1);
            //flag=1;
        }
    }
    /* check value*/



    printf("Enter Name Of the End Node: ");
    scanf("%s",&input_second);

    /* check value*/

    for(l=0; l<input_vertex; l++)
    {
        count1_place++;

        if (strcmp(input_second,NODE[l]) == 0)
        {
            store_last=(count1_place-1);
        }
    }

    dijkstra(Graph_Adj,input_vertex,store_first,store_last,NODE);
    return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startpath,int endpath,char NODE[][1000])
{

    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;


    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    //initialize pred[],distance[] and visited[]
    for(i=0; i<n; i++)
    {
        distance[i]=cost[startpath][i];
        pred[i]=startpath;
        visited[i]=0;
    }

    distance[startpath]=0;
    visited[startpath]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;

        //nextnode gives the node at minimum distance
        for(i=0; i<n; i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

        //check if a better path exists through nextnode
        visited[nextnode]=1;
        for(i=0; i<n; i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
    //print the path and distance of each node


    for(i=0; i<n; i++)
        if(i!=startpath )
        {
            if(i==endpath)
            {
                printf("\nSummation distance of node = %d",distance[i]);
                printf("\nPath= %s",NODE[i]);
                j=i;
                do
                {
                    j=pred[j];
                    printf("<-%s",NODE[j]);
                }
                while(j!=startpath);
                printf("\n");
                break;
            }
        }
}

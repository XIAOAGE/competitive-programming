#include <bits/stdc++.h>

#define MAX 26

using namespace std;

typedef struct TrieNode                     //Trie结点声明
{
    /*
    *More variables can be added for different problems
    */
    bool isStr;                            //标记该结点处是否构成单词
    struct TrieNode *next[MAX];            //儿子分支
}Trie;

void insert(Trie *root,const char *s)     //将单词s插入到字典树中
{
    if(root==NULL||*s=='\0')
        return;
    int i;
    Trie *p=root;
    while(*s!='\0')
    {
        //'0' can be changed to 'a', depending on the problem.
        if(p->next[*s-'0']==NULL)        //如果不存在，则建立结点
        {
            Trie *temp=(Trie *)malloc(sizeof(Trie));
            for(i=0;i<MAX;i++)
            {
                temp->next[i]=NULL;
            }
            temp->isStr=false;
            p->next[*s-'0']=temp;
            p=p->next[*s-'0'];
        }
        else
        {
            p=p->next[*s-'0'];
        }
        s++;
    }
    p->isStr=true;                       //单词结束的地方标记此处可以构成一个单词
}

int search(Trie *root,const char *s)  //查找某个单词是否已经存在 
{
    Trie *p=root;
    while(p!=NULL&&*s!='\0')
    {
        p=p->next[*s-'a'];
        s++;
    }
    return (p!=NULL&&p->isStr);      //在单词结束处的标记为true时，单词才存在 
}

void del(Trie *root)                      //释放整个字典树占的堆区空间
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(root->next[i]!=NULL)
        {
            del(root->next[i]);
        }
    }
    free(root);
}

int main()
{
    int n;      //n is the number of words        //n为建立Trie树输入的单词数，m为要查找的单词数
    char s[100];
    //#########initialize the root################
    Trie *root= (Trie *)malloc(sizeof(Trie));
    for(int i=0;i<MAX;i++)  root->next[i]=NULL;
    root->isStr=false;
    //############################################
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)     //build trie        //先建立字典树
    {
        scanf("%s",s);
        /*
        * Do whatever you like
        */
    }
    del(root);        //free the memories that are taken by the pointers   //释放空间很重要
    return 0;
}
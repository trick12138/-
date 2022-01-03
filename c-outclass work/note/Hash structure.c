#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    哈希结构:数据和地址的一种映射关系
    LZW
    aababa
    aa:0
    ba:1

    011

    映射关系:数学中的函数关系     哈希构造函数
    y(x)=x;     直接定值法
    哈希地址:地址不是真正意义上的地址(指针),而是抽象的参照地址,
        举例:数组的数组下标,充当哈希地址
    int arrayHash[10];
        y=x;
    arrayHash[1] = 1;
    arrayHash[2] = 2;
    arrayHash[1000] = 1000;
    用的比较多的哈希构造函数就是取余法:
    y = x%p;
    数据:1 4 19 11 23
        y=x%10;     //0-9;
    int arrayHash[10];
        arrayHash[1%10] = 1;
        arrayHash[4%10] = 4;
        arrayHash[19%10] = 19;
    //哈希冲突:在哈希地址中已经存在了元素
        arrayHash[11%10] /= 11
    //哈希冲突解决方法
        1.开放地址法
        2.数组链表
    有时候数据不满足数据结构需求时,自己构造函数
*/

//数组hash
struct pair
{
    int first;              //构造关键字,为构建hash地址做准备
    char second[20];        //数据
};

struct hashTable
{
    struct pair **table;    //二级指针便于判断为NULL的时候
    int sizeHash;           
    int divisor;            //y=x%divisor
};

struct hashTable *createHash(int divisor)
{
    struct hashTable *hash = (struct hashTable*)malloc(sizeof(struct hashTable));
    hash->sizeHash = 0;
    hash->divisor = divisor;
    hash->table = (struct pair **)malloc(sizeof(struct pair)*hash->divisor);
    //hash->table[divisor]: 一级指针
    for (int i = 0; i < divisor; i++)
    {
        hash->table[i] = NULL;      //指针没有内存
    }
    return hash;
}

//找到正确的地址去插入
int search(struct hashTable *hash, int first)
{
    //本来的地址可以通过构造函数求出来
    int pos = first % (hash->divisor);  //value%divisor
    int curPos = pos;
    do
    {
        //找一个可以使用的地址,直接返回
        if (hash->table[curPos] == NULL || hash->table[curPos]->first == first)
        {
            //hash->table[curPos]->first == first  比的不是hash地址,比的是关键字
            //hash地址中没有元素,或者存在相同键(first)的元素返回
            return curPos;
        }
        curPos = (curPos + 1) % (hash->divisor);//每一次往后移一位
    } while (curPos != pos);
    return curPos;
}

//插入
void insertHash(struct hashTable *hash,struct pair data)
{
    int pos = search(hash,data.first);
    if (hash->table[pos] == NULL)
    {
        hash->table[pos] = (struct pair*)malloc(sizeof(struct pair));
        memcpy(hash->table[pos],&data,sizeof(struct pair));
        hash->sizeHash++;
    }
    else    //冲突处理
    {
        if (hash->table[pos]->first == data.first)
        {
            //存在相同关键字的处理
            strcpy(hash->table[pos]->second,data.second);
        }
        else
        {
            printf("表满了,无法插入!\n");
            return;
        }
    }
}

void printHash(struct hashTable *hash)
{
    for (int i = 0; i < hash->divisor ; i++)
    {
        if (hash->table[i] == NULL)
        {
            printf("NULL\n");
        }
        else
            printf("%d %s\n",hash->table[i]->first,hash->table[i]->second);
    }
    printf("\n");
}

int main()
{
    struct hashTable *hash = createHash(10);
    struct pair array[5] = {1,"Kevin",11,"大水杯",13,"热到自然醒",15,"黑夜",3,"妖帝"};
    for (int i = 0; i < 5; i++)
    {
        insertHash(hash,array[i]);
    }
    struct pair data = {21,"莫帅!"};
    insertHash(hash,data);
    printHash(hash);
    struct pair data2 = {1,"大灰狼"};
    insertHash(hash,data2);
    printHash(hash);
    //STL:map:单映射
    system("pause");
    return 0;
}
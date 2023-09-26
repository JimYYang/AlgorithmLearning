#include <iostream>

const int N = 100010;


int head, e[N], ne[N], idx;

void init(){// 这样写是因为使用的是全局变量   全局变量会被初始化为0
    head = -1;
    idx = 0;
}
// 这里的头结点不是真的头结点  而是链表的第一个节点 要特别注意
void insert_head(int x){
    e[idx] = x;
    ne[idx] = head;// head idx都是指针
    head = idx++;
}

void insert(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k){
    ne[k] = ne[ne[k]];
}


int main(){
    int m;
    scanf("%d", &m);
    init();
    while(m--){
        int k, x;
        char op;
        scanf(" %c", &op);// 注意%c之前有一个空格  这样会跳过输入的空元素  而读入非空元素
        if(op == 'H'){
            scanf("%d", &x);
            insert_head(x);
        }
        else if(op == 'D'){
            scanf("%d", &k);
            if(k == 0)head = ne[head];
            remove(k - 1);
        }
        else {
            scanf("%d%d", &k, &x);
            insert(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i])printf("%d ", e[i]);
    return 0;
}

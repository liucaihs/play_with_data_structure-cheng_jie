#define MAXSIZE 20

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef int Status;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

Status GetElem(SqList, int, ElemType *);

Status ListInsert(SqList *, int, ElemType);

Status ListDelete(SqList *, int, ElemType *);

int main(void) {

    return 0;
}

/*
 * 获取元素操作
 */
Status GetElem(SqList L, int i, ElemType *e) {
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

/*
 * 插入操作
 * 在L中第i个位置之前插入新的数据元素e，L的长度加1
 */
Status ListInsert(SqList *L, int i, ElemType e) {
    if (L->length == MAXSIZE) {
        return ERROR;
    }
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    if (i <= L->length) {
        for (int k = L->length - 1; k >= i - 1; k--) {
            L->data[k + 1] = L->data[k];
        }
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) {
        return ERROR;
    }
    if (GetElem(*L, i, e) != OK) {
        return ERROR;
    }
    for (int k = i - 1; k <= L->length - 1; k++) {
        L->data[k] = L->data[k + 1];
    }
    L->length--;
    return OK;
}


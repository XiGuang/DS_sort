#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

template <class ElemType>
void QuickSort(ElemType elem[], int low, int high, int n)
// �������:������elem[low .. high]�е�Ԫ�ؽ��п�������
{
    ElemType e = elem[low];				// ȡ����Ԫ��
    int i = low, j = high;
    while (i < j)	{
        while (i < j && elem[j] >= e)	// ʹj�ұߵ�Ԫ�ز�С������Ԫ��
            j--;
        if (i < j)
            elem[i++] = elem[j];

        while (i < j && elem[i] <= e)	// ʹi��ߵ�Ԫ�ز���������Ԫ��
            i++;
        if (i < j)
            elem[j--] = elem[i];
    }
    elem[i] = e;
    //cout << "�������䣺" << low << "--" << high << ";����λ��Ϊ��" << i << endl;
    //Display(elem, n);
    //cout << endl;
    if (low < i-1)	QuickSort(elem, low, i - 1, n);		// ���ӱ�elem[low, i - 1]�ݹ�����
    if (i + 1 < high) QuickSort(elem, i + 1, high, n);	// ���ӱ�elem[i + 1, high]�ݹ�����
}


template<class T>//������ˣ��Ҷˣ�����Ԫ�ص���ֵ��λ��
int GetMid(T* begin, int Len) {
    if (Len <= 1)
        return 0;
    int a = begin[0], b = begin[Len / 2], c = begin[Len-1];
    int m = std::max(a, b), n = std::max(b, c);
    if (m == n)
        if (a > c)
            return 0;
        else
            return Len-1;
    else if (m != b && n!= b)
        if (a > c)
            return Len-1;
        else
            return 0;
    else
        return Len / 2;

}


template<class T>   //��������
int quick_sort_(T* begin, int Len) {

    T* A = begin;
    int mid = GetMid<int>(begin, Len);  //��λ
    std::swap(A[mid], A[0]);            //����λ��������һλ
    int Tem = A[0];                     //ѡȡ�ȽϵĻ�׼����λ��Ҳ���ǳ�ʼ�Ŀ�λ
    int i = 0, j = Len - 1;
    while(i < j) {
        while (A[j] >= Tem && i < j)
            j--;
        if(i < j)
            A[i++] = A[j];
        while (A[i] <= Tem && i < j)
            i++;
        if (i < j)
            A[j--] = A[i];
    }
    A[j] = Tem;
    return j;
}


template<class T>
void QuickSort2(T* A, int Len)
{
    if (Len <= 1) return;
    int k = quick_sort_(A, Len);
    QuickSort2<int>(A, k);
    QuickSort2<int>(&A[k + 1], Len - k - 1);
}

#endif


#include "Assistance.h"			// ���������
#include "QuickSort.h"			// ���������㷨
#include <cstdlib>
#include <ctime>
#include <chrono>
void Random(int *a,int n,int l,int r)//���ɷ�Χ��l~r�������
{
    srand(time(0));  //����ʱ������
    for(int i=0;i<n;i++){
        a[i]=rand()%(r-l+1)+l;//��������r~l�������
    }
}

int main(void)
{
    int a[100000];
	int n = 100000;
    Random(a,100000,0,100000);
    auto start = chrono::high_resolution_clock::now();
    //QuickSort2<int>(a, n);
    QuickSort(a, 0,n-1,n);
    auto end = chrono::high_resolution_clock::now();
    __int64 duration = (end - start).count();
    cout << "��������ʱ�䣺" << setprecision(10)
         << "��  " << duration / 1000000.0 << "ms"
         << endl;
    start = chrono::high_resolution_clock::now();
    QuickSort2<int>(a, n);
    end = chrono::high_resolution_clock::now();
    duration = (end - start).count();
    cout << "�Ľ����������ʱ�䣺" << setprecision(10)
         << "��  " << duration / 1000000.0 << "ms"
         << endl;

	return 0;					
}

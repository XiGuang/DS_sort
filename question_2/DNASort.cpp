//
// Created by 稀光 on 2022/5/25.
//

#include <iostream>
#include <cstring>

using namespace std;

int GetInverseNum(const char* DNA, int DNA_len);  // 得到DNA的逆序数

/**
 *
 * @param DNA_1
 * @param DNA_2
 * @param DNA_len DNA 的长度
 * @return 如果返回值 < 0，则表示 DNA1 小于 DNA2。
 *         如果返回值 > 0，则表示 DNA1 大于 DNA2。
 *         如果返回值 = 0，则表示 DNA1 等于 DNA2。
 */
int DNACmp(const char* DNA_1,const char* DNA_2, int DNA_len);

void SortDNA(char** DNAs, int DNA_len, int DNA_num);    // 用快排对DNA进行排序

int main(){
    int DNA_len(0),DNA_num(0); // DNA的长度和个数
    cin >> DNA_num >> DNA_len;
    char **DNAs = new char*[DNA_num];
    for(int i(0); i < DNA_num;++i){ // 读入字符串
        char *DNA = new char[DNA_len + 1];
        cin >> DNA;
        DNAs[i] = DNA;
    }

    SortDNA(DNAs, DNA_len, DNA_num);
    for(int i(0); i < DNA_num; ++i)
        cout << DNAs[i] << endl;
    return 0;
}

// 快排应该就不用注释了吧
void SortDNA(char** DNAs, int DNA_len, int DNA_num){    /// 快排
    char *DNA_temp(DNAs[0]);
    int low(0), high(DNA_num - 1);
    while(low < high){
        while(low < high && DNACmp(DNAs[high], DNA_temp, DNA_len) >= 0) --high; // 小的放前面
        if(low < high) DNAs[low++] = DNAs[high];
        while(low < high && DNACmp(DNAs[low], DNA_temp, DNA_len) <= 0) ++low;   // 大的放后面
        if(low < high) DNAs[high--] = DNAs[low];
    }
    DNAs[low] = DNA_temp;
    if(low - 1 > 0) SortDNA(DNAs, DNA_len, high - 1);
    if(DNA_num > low + 2) SortDNA(DNAs + low + 1, DNA_len, DNA_num - low - 1);
}

int DNACmp(const char* DNA_1,const char* DNA_2, int DNA_len){
    int inverse_num_1(GetInverseNum(DNA_1, DNA_len)), inverse_num_2(GetInverseNum(DNA_2, DNA_len));
    if(inverse_num_1 < inverse_num_2) return -1;    // 若第一个DNA的逆序数小于第二个，返回值小于0
    else if(inverse_num_1 > inverse_num_2) return 1;    // 若第一个DNA的逆序数大于第二个，返回值大于0
    return -strcmp(DNA_1,DNA_2);    // 逆序数相等时，返回负的字典比较结果（因为字典顺序从大到小排，与逆序数相反）
}

int GetInverseNum(const char* DNA, int DNA_len){
    int sum(0);
    for(int begin(0); begin < DNA_len - 1; ++begin){    // 循环比较计算出逆序数
        for(int back(begin + 1); back < DNA_len; ++back){
            if(DNA[begin] > DNA[back])
                ++sum;
        }
    }
    return sum;
}
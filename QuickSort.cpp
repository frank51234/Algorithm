#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& v, int lowPos, int highPos) {
    if (lowPos >= highPos) {
        return;
    }
    
    int pivotPos = lowPos;
    int i = lowPos, j = highPos;
    int key = v[i];  // 选择第一个元素为基准值，也就是说i这个位置变成了缺口
    
    while (i < j) {
        while (i < j && v[j] >= key) {
            --j;
        }
        if (i < j) {
            v[i] = v[j];  // 从后往前，找到比key小的元素，将其填充到缺口处i，此时j变为新的缺口
        }
        
        while (i < j && v[i] <= key) {
            ++i;
        }
        if (i < j) {
            v[j] = v[i]; // 从前往后，找到比key大的元素，将其填充到缺口处j，此时i变为新的缺口
        }
    }
    
    v[i] = key; // 将key填充到最终的缺口处
    pivotPos = i;
    
    quickSort(v, lowPos, pivotPos - 1);
    quickSort(v, pivotPos + 1, highPos);
}

int main()
{  
    vector<int> v{5, 9, 10, 1, 2, 4};

    for (unsigned int i = 0; i < v.size() ; ++i) {
        cout << "i:" << v[i] << endl;
    }
    
    quickSort(v, 0, v.size() - 1);
    
    cout << "--------------" << endl;
    
    for (unsigned int i = 0; i < v.size() ; ++i) {
        cout << "i:" << v[i] << endl;
    }
}

#include <iostream>
using namespace std;

//快速排序
int partition(int *arr, unsigned int start, unsigned int end) {
  if (arr == nullptr) return -1;
  int temp = *(arr + start);
  while (start < end) {
    while (*(arr + end) > temp && start < end) end--;
    if (start < end) *(arr + start++) = *(arr + end);

    while (*(arr + start) < temp && start < end) start++;
    if (start < end) *(arr + end--) = *(arr + start);
  }

  *(arr + start) = temp;
  return start;
}
void QuickSort(int *arr, unsigned int start, unsigned int end) {
  if (arr == nullptr || start >= end) return;
  int k;
  if (start < end) {
    k = partition(arr, start, end);
    QuickSort(arr, start, k - 1);
    QuickSort(arr, k + 1, end);
  }
}

//堆排序
void buildDown(int *arr, int arrLength, int rootIndex) {
  if (arr == nullptr || arrLength <= 0 || rootIndex < 0) return;

  int root = arr[rootIndex];
  int childIndex = (rootIndex * 2 + 1);  //左孩子

  while (childIndex < arrLength) {
    //如果还有右孩子
    if (childIndex < arrLength - 1 && arr[childIndex] <= arr[childIndex + 1])
      childIndex++;  //移动到较大的子节点

    if (root < arr[childIndex]) {
      arr[rootIndex] = arr[childIndex];
      rootIndex = childIndex;
      childIndex = (rootIndex * 2 + 1);
    } else
      break;
  }
  arr[rootIndex] = root;
}
void HeapSort(int *arr, int arrLength) {
  int temp;

  //构建大顶堆  (arrLength - 2) / 2 为最后一个节点的父节点
  for (int rootIndex = (arrLength - 2) / 2; rootIndex >= 0; rootIndex--)
    buildDown(arr, arrLength, rootIndex);

  //开始堆排序
  for (int i = arrLength - 1; i >= 0; i--) {
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    buildDown(arr, i, 0);
  }
}

void merge(int *arr, int arrLength) {}

void printArray(int *arr, int n) {
  if (arr == nullptr) return;
  for (int i = 0; i < n; i++) cout << *(arr + i) << "\t";
  cout << endl;
}

int main() {
  int arr[] = {2, 5, 9, 21, 5, 1, 6, 12, 6, 5};
  QuickSort(arr, 0, 9);
  // HeapSort(arr,10);
  printArray(arr, 10);
}
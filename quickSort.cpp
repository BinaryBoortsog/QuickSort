#include <iostream>
#include <vector>
using namespace std;

// 두 값을 교환하는 함수
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 세 값의 중간값을 피벗으로 선택하는 함수
int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    
    // 첫 번째, 중간, 마지막 값을 비교하여 중간값을 선택
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    swap(arr[mid], arr[high]);  // 중간값을 피벗으로 설정하여 마지막 위치로 이동

    return arr[high];  // 피벗 반환
}

// 배열을 분할하는 함수
int partition(vector<int>& arr, int low, int high, vector<int>& pivots) {
    int pivot = medianOfThree(arr, low, high);  // 피벗 선택

    pivots.push_back(pivot);  // 피벗 값을 저장

    int i = low - 1;  // 작은 값의 인덱스

    // 피벗보다 작은 값을 왼쪽으로, 큰 값을 오른쪽으로 이동
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // 작은 값을 왼쪽으로 이동
        }
    }

    swap(arr[i + 1], arr[high]);  // 피벗을 올바른 위치로 이동

    return i + 1;  // 피벗 위치 반환
}

// 퀵 정렬 알고리즘 구현
void quickSort(vector<int>& arr, int low, int high, vector<int>& pivots) {
    if (low < high) {
        int pi = partition(arr, low, high, pivots);  // 분할 후 피벗의 위치

        quickSort(arr, low, pi - 1, pivots);  // 피벗을 기준으로 왼쪽 정렬
        quickSort(arr, pi + 1, high, pivots);  // 피벗을 기준으로 오른쪽 정렬
    }
}

// 배열 출력 함수
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int N;
    cin >> N;  // 배열의 크기 입력
    vector<int> arr(N);  // 크기 N의 배열 생성
    for (int i = 0; i < N; i++) {
        cin >> arr[i];  // 배열 요소 입력
    }
    vector<int> pivots;  // 피벗 값을 저장할 벡터

    quickSort(arr, 0, N - 1, pivots);  // 퀵 정렬 실행
    printArray(arr);  // 정렬된 배열 출력
    printArray(pivots);  // 피벗 값 출력

    return 0;
}

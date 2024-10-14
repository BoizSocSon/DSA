#include "iostream"
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void heapify(int a[], int i, int n) { // hàm vun lại đống với nút cha là nút chỉ định
    int l = 2*i;
    int r = 2*i + 1;
    int max = i;
    if(l < n && a[l] > a[i]) max = l;
    if(r < n && a[r] > a[i]) max = r;
    if(max != i) {
        swap(a[max], a[i]);
        heapify(a, max, n);
    }
}
void build_heap (int a[], int n) { // sắp xếp thành 1 cây hoàn hảo với nút cha lớn hơn nút con
    for(int i = n/2 ; i >= 1 ; i--) {
        heapify(a, i, n);
    }
}
void heap_sort(int a[], int n) {
    build_heap(a, n);
    for(int i = n ; i > 1; i++) {
        swap(a[1], a[i]);
        heapify(a, 1, i-1);
    }
}
int main () {
    int n, a[100]; cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> a[i];
    }
    heap_sort(a, n);
    
    for(int i=0 ; i<n ; i++) cout << a[i] << " ";
    
    cout << endl;
    return 0;
}
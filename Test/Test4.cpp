#include "iostream"
using namespace std;

void merge(int a[], int b[], int n, int m) {
    int c[100];
    int i=0;
    int j=0;
    int index=0;
    while(i<n && j<m) {
        if(a[i] < b[j]) {
            c[index] = a[i];
            i++;
            index++;
        }
        if(b[j] < a[i]) {
            c[index] = b[j];
            index++;
            j++;
        }
    }
    while(i<n) {
        c[index] = a[i];
        index++;
        i++;
    }
    while(j<m) {
        c[index] = b[j];
        index++;
        j++;
    }
}

int *merge(int *a, int *b, int n, int m) {
   int *c = new int(n + m);
   int i=0;
   int j=0;
   int index=0;
   while(i<n && j<m) {
       if(a[i] < b[j]) {
           c[index] = a[i];
           i++;
           index++;
       }
       if(b[j] < a[i]) {
           c[index] = b[j];
           index++;
           j++;
       }
   }
   while(i<n) {
       c[index] = a[i];
       index++;
       i++;
   }
   while(j<m) {
       c[index] = b[j];
       index++;
       j++;
   }
   return c;
}
int *merge_sort(int *a, int n) {
   if(n == 1) {
       return a;;
   }
   
   int mid = n/2;
   int *x = new int(mid);
   int *y = new int(n-mid);
   for(int i=0; i<mid; i++) {
       x[i] = a[i];
   }
   for(int i=0; i<n-mid; i++) {
       y[i]= a[mid+i];
   }
   x = merge_sort(x, mid);
   y = merge_sort(y, n-mid);
  return merge(x, y, mid, n-mid);
}
int main () {
   int n, a[100]; cin >> n;
   for(int i=0; i<n; i++) cin >> a[i];
   int *b = merge_sort(a, n);
   for(int i=0; i<n; i++) {
       cout << b[i] <<" ";
   }
   cout << endl;
   return 0;
}


#include<iostream>
#include<vector>
using namespace std;
#define max 100
void nhapmang(int a[], int &n){
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
}
void suatmang(int a[], int n){
    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
void selectionsort(int a[], int n){ // Sap xep chon O(n^2)
    for (int i = 0; i < n - 1 ; i ++){
        int min = i;
        for (int j = i + 1; j < n; j ++){
            if(a[j] < a[min]) min = j;
        }
    swap(a[i], a[min]);
    }
}
void bubblesort(int a[], int n){ // Sap xep noi bot O(n^2)
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - 1; j ++){
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}
void insertionsort(int a[], int n){ // Sap xep chen O(n^2)
    for(int i = 1; i < n; i ++){
        // lay ra ptu o vi tri i
        int x = a[i], pos = i - 1; // pos la vi tri hop li cho x(nen i -1 la vi tri tiem nang dau tien ma minh xet)
        while(pos >=0 && x < a [pos]){
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

void merge(int a[], int l, int m, int r){ // thuat toan merge 2 hang con cua mergesort Sapxeptron O(nlogn)
    int i = l, j = m + 1, k = 0, n = r - l + 1;
    int *B = new int[n];
    while((i< m + 1) && (j < r + 1)){
        if(a[i] < a[j]){
            B[k]=a[i];
            k++;
            i++;
        }
        else
        {
            B[k] = a[j];
            k++;;
            j++;
        }
    }
    while(i < m +1){
        B[k] = a[i];
        k++;
        i++;
    }
    while(j< r + 1){
        B[k] = a[j];
        k++;j++;
    }
    i = l;
    for(k = 0; k < n; k ++){
        a[i] = B[k];
        i++;
    }
    delete []B;
}
void mergesort(int a[], int l, int r){ // thuat toan sapxeptron
    if(l >= r) return;
    int m = (l+r)/2;
    mergesort(a, l, r);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}

int partition(int a[], int l, int r){ // ham chia nho mang cua quicksort
    int pivot = a[r]; // vi tri ben phai ngoai cung
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= pivot ){
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}
void quicksort(int a[], int l, int r){
    if( l >= r ) return;
    int p = partition(a, l, r); // tìm vị trí để chia đôi quick sort
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}

int main() {
    int a[max], n;
    cin >> n;
    nhapmang(a, n);
    quicksort(a, 0, n -1);
    suatmang(a, n);
    return 0;
}

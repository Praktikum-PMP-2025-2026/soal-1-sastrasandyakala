#include <stdio.h>
#include <stdlib.h>

// Fungsi komparator untuk qsort (mengurutkan secara menaik/ascending)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int capacity = 10; // Kapasitas awal array dinamis
    int size = 0;
    int *arr = (int*)malloc(capacity * sizeof(int));

    if (arr == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1; 
    }

    int num;
    // Membaca input data hingga menemukan nilai -1
    while (scanf("%d", &num) == 1 && num != -1) {
        // Jika array sudah penuh, gandakan kapasitas memorinya
        if (size == capacity) {
            capacity *= 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Gagal merealokasikan memori.\n");
                return 1;
            }
        }
        arr[size] = num; // Semua nilai sebelum -1 dianggap valid
        size++;
    }

    // Memastikan jumlah data minimal 1 sebelum diproses
    if (size < 1) {
        free(arr);
        return 0;
    }

    // Mengurutkan data menggunakan Quick Sort
    qsort(arr, size, sizeof(int), compare);

    // Menampilkan jumlah data (COUNT)
    printf("COUNT %d ", size);

    // Menampilkan data yang sudah diurutkan (SORTED)
    printf("SORTED ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf(" ");

    // Menampilkan MEDIAN
    printf("MEDIAN ");
    if (size % 2 != 0) {
        // Jika banyak data ganjil, cetak elemen tengah secara langsung
        printf("%d\n", arr[size / 2]);
    } else {
        // Jika genap, hitung rata-rata dua elemen tengah
        int mid1 = arr[(size / 2) - 1];
        int mid2 = arr[size / 2];
        float median = (mid1 + mid2) / 2.0;
        
        // Cetak dengan dua angka di belakang koma untuk menangani .50 atau .00
        printf("%.2f\n", median);
    }

    // Membebaskan memori setelah selesai digunakan
    free(arr);
    return 0;
}

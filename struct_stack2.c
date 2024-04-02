#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int twoStacks(int maxSum, int n, int m, int* a, int* b) {
    int i = 0; // Pointer untuk stack a
    int j = 0; // Pointer untuk stack b
    int sum = 0; // Jumlah nilai yang diambil dari kedua stack
    int count = 0; // Jumlah nilai yang diambil secara maksimum

    // Hitung jumlah nilai yang bisa diambil dari stack a tanpa melebihi maxSum
    while (i < n && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
        count++;
    }

    int maxCount = count; // Simpan nilai maksimum sementara

    // Iterasi melalui stack b dan perbarui nilai maksimum
    while (j < m && i >= 0) {
        sum += b[j];
        j++;

        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }

        if (sum <= maxSum) {
            maxCount = max(maxCount, i + j); // Perbarui nilai maksimum jika diperlukan
        }
    }

    return maxCount;
}

int main() {
    int g;
    scanf("%d", &g);

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int b[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        int result = twoStacks(maxSum, n, m, a, b);

        printf("%d\n", result);
    }

    return 0;
}

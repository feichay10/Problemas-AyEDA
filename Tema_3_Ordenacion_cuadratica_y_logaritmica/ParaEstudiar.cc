// Insertion:
// 44  55  12  42  94  18  06  67  i = 1
// 44  55  12  42  94  18  06  67  i = 2
// 12  44  55  42  94  18  06  67  i = 3
// 12  42  44  55  94  18  06  67  i = 4
// 12  42  44  55  94  18  06  67  i = 5
// 12  18  42  44  55  94  06  67  i = 6
// 06  12  18  42  44  55  94  67  i = 7
// 06  12  18  42  44  55  67  94  i = 8

// Selection:
// i = 0 // 44  55  12  42  94  18  06  67  // j = 6
// i = 1 // 06  12  55  42  94  18  44  67  // j = 2
// i = 2 // 06  12  18  42  94  55  44  67  // j = 5
// i = 3 // 06  12  18  42  94  55  44  67  // j = 3
// i = 4 // 06  12  18  42  44  55  94  67  // j = 6
// i = 5 // 06  12  18  42  44  55  94  67  // j = 5
// i = 6 // 06  12  18  42  44  55  67  94  // j = 7
// i = 7 // 06  12  18  42  44  55  67  94  // 

// ShakeSort:
//     44  55  12  42  94  18  06  67
// ->  44  12  42  55  18  06  67  94  ->
// <-  06  44  12  42  55  18  67  94  ->
// ->  06  12  42  44  55  18  67  94  ->
// <-  06  12  18  42  44  55  67  94  <-
// --- 06  12  18  42  44  55  67  94 ---

// QuickSort:
//  44  55  12  42  94  18  06  67  |  PIV = (0 + 7) / 2 = 3; PIV = 42
//  06  55  12  42  94  18  44  67  |  i = 0 - i = 6
//  06  18  12  42  94  55  44  67  |  i = 1 - i = 5
//  06  18  12  42  94  55  44  67  |  PIV = 18 | i = 1 - i = 2
//  06  12  18  42  94  55  44  67  |  PIV = 55 | i = 4 - i = 7
//  06  12  18  42  44  55  67  94  |  i = 4 - i = 6

// MergeSort:
// Secuencia:  44  55  12  42  94  18  06  67
// Izquierda----------------------------------------
// Division:  [44  55  12  42]  [94  18  06  67]
// Division:  [44  55] [12  42]  [94  18  06  67]
// Mezclado:  [44  55] [12  42]  [94  18  06  67]
// Division:  [44  55] [12][42]  [94  18  06  67]
// Mezclado:  [44  55] [12  42]  [94  18  06  67]
// Mezclado:  [12  42  44  55]  [94  18  06  67]
// Derecha------------------------------------------
// Division:  [12  42  44  55]  [94  18]  [06  67]
// Division:  [12  42  44  55]  [94] [18]  [06  67]
// Mezclado:  [12  42  44  55]  [18  94]  [06  67]
// Division:  [12  42  44  55]  [18  94]  [06]  [67]
// Mezclado:  [12  42  44  55]  [18  94]  [06  67]
// Mezclado:  [12  42  44  55]  [06  18  67  94]
// Entero-------------------------------------------
// Mezclado:  [06  12  18  42  44  55  67  94]

void Insertion(std::vector<int> vector, int size) {
    for (int i = 1; i < size; i++) {
        int aux = vector[i];
        int j = i - 1;
        while(j >= 0 && vector[j] > aux) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = aux;
    }
}

void Selection(std::vector<int> vector, int size) {
    int min;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i + 1; i < size; j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
        std::swap(vector[i], vector[min]);
    }
}

void QuickSort(std::vector<int> vector, int ini, int fin) {
    int i = ini;
    int f = fin;
    int piv = vector[(i + f) / 2];

    while (i <= f) {
        while (vector[i] < piv) i++;
        while (vector[f] > piv) f--;
        if (i <= f) {
            std::swap(vector[i], vector[f]);
            i++;
            f--;
        }
    }
    if (ini < f) QuickSort(vector, ini, f);
    if (i < fin) QuickSort(vector, i, fin);
}

void MergeSort(std::vector<int> vector, int ini, int fin) {
    if (ini < fin) {
        int cen = (ini + fin) / 2;
        MergeSort(vector, ini, cen);
        MergeSort(vector, cen + 1, fin);
        Mix(vector, ini, cen, fin);
    }
}

void Mix(std::vector<int> vector, int ini, int cen, int fin) {
    int i = ini;
    int j = cen + 1;
    std::vector<int> aux(fin + 1);
    for(int k = ini; i <= fin; k++) {
        if (i <= cen && (j > fin || vector[i] < vector[j])) {
            aux[k] = vector[i];
            i++;
        } else {
            aux[k] = vector[j];
            j++;
        }
    }

    for(int k = ini; i < fin; k++) {
        vector[k] = aux[k];
    }
}

void ShellSort(std::vector<int> vector, int size) {
    unsigned delta = size;
    while (delta > 1) {
        delta = delta / 2;
        DeltaSort(vector, delta, size);
    }
}

void DeltaSort(std::vector<int> vector, int delta, int size) {
    int aux;
    for (int i = delta; i < size; i++) {
        aux = vector[i];
        int j = i;
        while (j >= delta && vector[j - delta] > aux) {
            vector[j] = vector[j - delta];
            j = j - delta;
        }
        vector[j] = aux;
    }
}
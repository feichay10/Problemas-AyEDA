# Codigos de Ordenacion

## Insertion
```c++
void Insertion(std::vector<int> vector, int size) {
    for (int i = 1; i < size; i++) {
        int aux = vector[i];
        int j = i - 1;
        while (j >= 0 && vector[j] > aux) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = aux;
    }
}
```

## Selection
```c++
void Selection(std::vector<int> vector, int size) {
    int min; // Puede ser max
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
        // Intercambio de elementos
        std::swap(vector[i], vector[min]);
    }
}
```

## QuickSort
```c++
void QuickSort(std::vector<int> vector, int ini, int fin) {
    int i = ini;
    int f = fin;
    int piv = vector[(i + f) / 2];
    while (i <= f) {
        while(vector[i] < piv) i++;
        while(vector[f] > piv) f--;
        if (i <= f) {
            std::swap(vector[i], vector[f]);
            i++;
            f--;
        }
    }
    if (ini < f) QuickSort(vector, ini, f);
    if (i < fin) QuickSort(vector, i, fin);
}
```

## MergeSort
```c++
void MergeSort(std::vector<int> vector, int ini, int fin) {
    if (ini < fin) {
        int cen = (ini + cen) / 2;
        MergeSort(vector, ini, cen);       // Subsecuencia 1: izquierda
        MergeSort(vector, cen + 1, fin);    // Subsecuencia 2: derecha
        Mix(vector, ini, cen, fin);
    }
}

void Mix(std::vector<int> vector, int ini, int cen, int fin) {
    int i = ini;
    int j = cent + 1;
    std::vector<int> aux(fin + 1);

    for (int k = ini; k <= fin; k++) {
        if (i <= cen && (j > fin || vector[i] < vector[j])) {
            aux[k] = vector[i];
            i++;
        } else {
            aux[k] = vector[j];
            j++;
        }
    }

    // Copia al vector original
    for (int k = ini; k <= fin; k++) {
        vector[k] = aux[k];
    }
}
```

## ShellSort
```c++
void ShellSort(std::vector<int> vector, int size) {
    unsigned delta = size;
    while (delta > 1) {
        delta = delta / 2;
        DeltaSort(vector, size, delta);
    }
}

void DeltaSort(std::vector<int> vector, int size, int delta) {
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
```
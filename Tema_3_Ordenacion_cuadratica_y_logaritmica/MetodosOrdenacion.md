# Codigos de Ordenacion

## Insertion
Algoritmo cuadrático que recorre la secuencia de izquierda a derecha, insertando cada elemento en su posición correcta. Tiene complejidad O(n^2).
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
Algoritmo cuadrático que busca el mínimo (o máximo) y lo intercambia con el primer elemento.
Tiene complejidad O(n^2).
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
        std::swap(vector[i], vector[min]);
    }
}
```

### ShakeSort
Algoritmo de ordenación que mejora el algoritmo de la burbuja, intercambiando elementos de izquierda a derecha y de derecha a izquierda.
Tiene complejidad O(n^2).
```c++
void shakeSort(std::vector<int> vector, int size) {
    int start = 1;
    int end = size - 1;
    int cam = size;
    while (start <= end) {
        for (int i = end; i >= start; i--) {
            if (vector[i] < vector[i - 1]) {
                std::swap(vector[i - 1], vector[i]);
                cam = i;
            }
        }
        start = cam + 1;
        for (int i = start; i <= end; i++) {
            if (vector[i] < vector[i - 1]) {
                std::swap(vector[i - 1], vector[i]);
                cam = i;
            }
        }
        end = cam - 1;
    }
}
```

## QuickSort
Algoritmo divide y vencerás que selecciona un pivote y divide la secuencia en dos subsecuencias, ordenándolas recursivamente.
Tiene complejidad O(n log n).
```c++
void QuickSort(std::vector<int> &vector, int ini, int fin) {
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
Algoritmo divide y vencerás que divide la secuencia en dos subsecuencias, ordenándolas recursivamente y mezclándolas.
Tiene complejidad O(n log n).
```c++
void MergeSort(std::vector<int> vector, int ini, int fin) {
    if (ini < fin) {
        int cen = (ini + fin) / 2;
        MergeSort(vector, ini, cen);       // Subsecuencia 1: izquierda
        MergeSort(vector, cen + 1, fin);    // Subsecuencia 2: derecha
        Mix(vector, ini, cen, fin);
    }
}

void Mix(std::vector<int> vector, int ini, int cen, int fin) {
    int i = ini;
    int j = cen + 1;
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
Mejora del algoritmo de ordenamiento por inserción que permite intercambiar 
elementos lejanos para que la lista se ordene más rápidamente.
Tiene complejidad O(n log n).
```c++
void ShellSort(std::vector<int> vector, int size) {
    unsigned delta = size;
    while (delta > 1) {
        delta = delta / 2;
        DeltaSort(vector, size, delta);
    }
}

void DeltaSort(std::vector<int> vector, int size, int delta) {
    for (int i = delta; i < size; i++) {
        int aux = vector[i];
        int j = i;
        while (j >= delta && vector[j - delta] > aux) {
            vector[j] = vector[j - delta];
            j = j - delta;
        }
        vector[j] = aux;
    }
}
```

## HeapSort
Algoritmo de ordenación que utiliza una estructura de datos de arbol binario para ordenar los elementos.
Usa un heap binario para almacenar los elementos y extraer el máximo (o mínimo) en cada iteración.
Tiene complejidad O(n log n).

## RadixSort
Algoritmo de ordenación que ordena los elementos por dígitos, de menor a mayor peso.
Tiene complejidad O(n k), siendo k el número de dígitos.
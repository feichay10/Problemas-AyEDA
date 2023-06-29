void Insertion(std::vector<int> vector, int size) {
    for (int i = 1; i < size; i++) {
        int aux = vector[i];
        int j = i + 1;
        while (j >= 0 && vector[j] > aux) {
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
        for (int j = i + 1; j < size; j++) {
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

    for (int k = ini; k <= fin; k++) {
        vector[aux] = aux[k];
    }
}
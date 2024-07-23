#include <stdio.h>
#include <stdbool.h>

#define N 4

void backtracking_permutari(int set[N], int permutare[N], bool folosit[N], int poz) {
    if (poz == N) {
        // Am ajuns la o permutare completă, o afișăm
        for (int i = 0; i < N; i++) {
            printf("%d ", permutare[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!folosit[i]) {
            permutare[poz] = set[i];
            folosit[i] = true;
            backtracking_permutari(set, permutare, folosit, poz + 1);
            folosit[i] = false;
        }
    }
}

int main() {
    int set[N] = {1, 2, 3, 4};
    int permutare[N];
    bool folosit[N] = {false};

    printf("Permutarile sunt:\n");
    backtracking_permutari(set, permutare, folosit, 0);

    return 0;
}

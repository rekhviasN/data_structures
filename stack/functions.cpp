#include "functions.h"
void make_test_cases(int *ids, char **data, int num_cases) {

    for (int i = 0; i < num_cases; i++) {
        ids[i] = rand() % MAX_ID + 1;
        for (int j = 0; j < BUFFER_SIZE - 1; j++) {
            data[i][j] = 'a' + i;
        }
        data[i][BUFFER_SIZE - 1] = '\0';
    }
}

void display_test_cases(int *ids, char **data, int num_cases) {
    cout << "Displaying test cases..." << endl;
    for (int i = 0; i < num_cases; i++) {
        cout << ids[i] << ": " << data[i] << endl;
    }
}

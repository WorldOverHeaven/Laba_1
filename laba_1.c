#include <stdio.h>
#include <stdlib.h>

struct complex{
    float real;
    float imagine;
};

float *create_array(int);
float kvad(float);
float *map(float(*)(float), float*, int);
void print_array(float*, int);
float mod(float);
float *where(float*, int);
float *concatenation(float*, int, float*, int);

struct complex com_kvad(struct complex);
struct complex *com_create_array(int);
struct complex *com_map(struct complex(*)(struct complex), struct complex*, int);
void com_print_array(struct complex*, int);
float com_mod(struct complex);
float *com_where(struct complex*, int);
struct complex *com_concatenation(struct complex*, int, struct complex*, int);

int get_size(int*);
int get_choose(int*);
int get_float(float*);
float *scan_array(int);
struct complex *com_scan_array(int);

int main() {
    int choose;
    printf("Choose real or complex number\nFor real number enter '0'\nFor complex number enter '1'\n");
    get_choose(&choose);
    if (choose == 0) {
        int array_size_1, array_size_2;
        float *array_1, *array_2, *array_map, *array_where, *array_concatenation;

        printf("Enter the size of the first array\n");
        get_size(&array_size_1);
        printf("Choose if you want to enter array yourself or make it randomly\nTo enter array yourself enter 0\nFor generating array enter 1\n");
        get_choose(&choose);
        if (choose == 0) {
            array_1 = scan_array(5);
            print_array(array_1, array_size_1);
        }

        else {
            array_1 = create_array(array_size_1);
            print_array(array_1, array_size_1);
        }

        printf("Enter the size of the second array\n");
        get_size(&array_size_2);
        printf("Choose if you want to enter array yourself or make it randomly\nTo enter array yourself enter 0\nFor generating array enter 1\n");
        get_choose(&choose);
        if (choose == 0) {
            array_2 = scan_array(array_size_2);
            print_array(array_2, array_size_2);
        }

        else {
            array_2 = create_array(array_size_2);
            print_array(array_2, array_size_2);
        }

        printf("Array_map\n");

        array_map = map(kvad, array_1, array_size_1);
        print_array(array_map, array_size_1);

        printf("Array_where\n");

        array_where = where(array_2, array_size_2);
        print_array(array_where, array_size_2);

        printf("Array_concatenation\n");

        array_concatenation = concatenation(array_1, array_size_1, array_2, array_size_2);
        print_array(array_concatenation, array_size_1 + array_size_2);

        free(array_1);
        free(array_2);
        free(array_map);
        free(array_where);
        free(array_concatenation);
    }

    else {
        int array_size_1, array_size_2;
        float *array_where;
        struct complex *array_1, *array_2, *array_map, *array_concatenation;

        printf("Enter the size of the first array\n");
        get_size(&array_size_1);
        printf("Choose if you want to enter array yourself or make it randomly\nTo enter array yourself enter 0\nFor generating array enter 1\n");
        get_choose(&choose);
        if (choose == 0) {
            array_1 = com_scan_array(5);
            com_print_array(array_1, array_size_1);
        }

        else {
            array_1 = com_create_array(array_size_1);
            com_print_array(array_1, array_size_1);
        }

        printf("Enter the size of the second array\n");
        get_size(&array_size_2);
        printf("Choose if you want to enter array yourself or make it randomly\nTo enter array yourself enter 0\nFor generating array enter 1\n");
        get_choose(&choose);
        if (choose == 0) {
            array_2 = com_scan_array(array_size_2);
            com_print_array(array_2, array_size_2);
        }

        else {
            array_2 = com_create_array(array_size_2);
            com_print_array(array_2, array_size_2);
        }

        printf("Array_map\n");

        array_map = com_map(com_kvad, array_1, array_size_1);
        com_print_array(array_map, array_size_1);

        printf("Array_where\n");

        array_where = com_where(array_2, array_size_2);
        print_array(array_where, array_size_2);

        printf("Array_concatenation\n");

        array_concatenation = com_concatenation(array_1, array_size_1, array_2, array_size_2);
        com_print_array(array_concatenation, array_size_1 + array_size_2);

        free(array_1);
        free(array_2);
        free(array_map);
        free(array_where);
        free(array_concatenation);
    }

    return 0;
}

float *create_array(int size) {
    float *p;
    p = (float *) malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        p[i] = rand()%10;
    }
    return p;
}

float kvad(float a) {
    return a*a;
}

float *map(float (*function) (float), float* arr, int size) {
    float *p = (float *) malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        p[i] = function(arr[i]);
    }
    return p;
}

void print_array(float* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f\n", arr[i]);
    }
    printf("\n");
}

float mod(float a) {
    return a>5?1:0;
}

float *where(float* arr, int size) {
    float *p = (float *) malloc(size * sizeof(float));
    for (int i = 0; i < size; ++i) {
        p[i] = mod(arr[i]);
    }
    return p;
}

float *concatenation(float* arr_1, int size_1, float* arr_2, int size_2) {
    float *p = (float *) malloc((size_1 + size_2) * sizeof(float));
    for (int i = 0; i < (size_1); ++i) {
        p[i] = arr_1[i];
    }
    for (int i = 0; i < (size_2); ++i) {
        p[i + size_1] = arr_2[i];
    }
    return p;
}

struct complex com_kvad(struct complex cm) {
    float a = cm.real, i = cm.imagine;
    cm.real = a*a - i*i;
    cm.imagine = 2*a*i;
    return cm;
}

struct complex *com_create_array(int size) {
    struct complex *p = malloc(size * sizeof(struct complex));
    //p = (struct complex *) malloc(size * sizeof(struct complex));
    for (int i = 0; i < size; i++) {
        p[i].imagine = rand()%10;
        p[i].real = rand()%10;
    }
    return p;
}

void com_print_array(struct complex* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f + %f i\n", arr[i].real, arr[i].imagine);
    }
    printf("\n");
}

struct complex *com_map(struct complex(*function)(struct complex), struct complex* arr, int size) {
    struct complex *p = (struct complex *) malloc(size * sizeof(struct complex));
    for (int i = 0; i < size; i++) {
        p[i] = function(arr[i]);
    }
    return p;
}

float com_mod(struct complex f) {
    if (f.real > f.imagine) {
        return 1;
    }
    else {
        return 0;
    }
}

float *com_where(struct complex* arr, int size) {
    float *p = (float *) malloc(size * sizeof(float));
    for (int i = 0; i < size; ++i) {
        p[i] = com_mod(arr[i]);
    }
    return p;
}

struct complex *com_concatenation(struct complex* arr_1, int size_1, struct complex* arr_2, int size_2) {
    struct complex *p = (struct complex *) malloc((size_1 + size_2) * sizeof(struct complex));
    for (int i = 0; i < (size_1); ++i) {
        p[i].real = arr_1[i].real;
        p[i].imagine = arr_1[i].imagine;
    }
    for (int i = 0; i < (size_2); ++i) {
        p[i + size_1].real = arr_2[i].real;
        p[i + size_1].imagine = arr_2[i].imagine;
    }
    return p;
}

int get_size(int* a) {
    int n;
    do {
        n = scanf("%d", a);
        if ((n == 0) || ( *a < 1)) {
            printf("Error, enter integer value more then 0\n");
            scanf("%*[^\n]");
        }
    } while ((n == 0) || (*a < 1));
    return n;
}

int get_choose(int* a) {
    int n;
    do {
        n = scanf("%d", a);
        if ((n == 0) && (*a != 1) && (*a != 0))  {
            printf("Error, enter 0 or 1\n");
            scanf("%*[^\n]");
        }
    } while ((n == 0) && (*a != 1) && (*a != 0));
    return n;
}

int get_float(float* a) {
    int n;
    do {
        n = scanf("%f", a);
        if (n == 0) {
            printf("Error, enter correct value\n");
            scanf("%*[^\n]");
        }
    } while (n == 0);
    return n;
}

float *scan_array(int size) {
    float *p;
    p = (float *) malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        printf("Enter number\n");
        get_float(&p[i]);
    }
    return p;
}

struct complex *com_scan_array(int size) {
    struct complex *p;
    p = (struct complex *) malloc(size * sizeof(struct complex));
    for (int i = 0; i < size; i++) {
        printf("Enter real\n");
        get_float(&p[i].real);
        printf("Enter imagine\n");
        get_float(&p[i].imagine);
    }
    return p;
}

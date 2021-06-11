include <stdlib.h>
#include <stdio.h>
#include "matrices.h"

void mx_free(TMatrix* m) {
    if (m != NULL)
        if (m->a != NULL) {
            free(m->a);
            free(m);
        }
}

void mx_print(TMatrix* m) {
    unsigned int i, j;

    if (m != NULL) {
        if (m->a != NULL) {
            for (i = 0; i < m->m; i++) {
                for (j = 0; j < m->n; j++)
                    printf("%8.2lf", m->a[i * m->n + j]);
                printf("\n");
            }
        }
    }
}

TMatrix* mx_identity(unsigned int n) {
    unsigned int i, j;
    TMatrix* m = NULL;

    m = (TMatrix*)malloc(sizeof(TMatrix));
    if (m != NULL) {
        m->a = (double*)malloc(n * n * sizeof(double));
        if (m->a != NULL) {
            m->n = m->m = n;
            for (i = 0; i < m->m; i++)
                for (j = 0; j < m->n; j++)
                    m->a[i * n + j] = i == j ? 1 : 0;
        }
        else {
            free(m);
            m = NULL;
        }
    }
    return m;
}

/**
Sort with a snake
*/
void mx_sort(TMatrix* m)
{
    // Sorting the linearized matrix
    for (int i = 0; i + 1 < m->m * m->n; ++i)
    {
        for (int j = i + 1; j < m->m * m->n; ++j)
        {
            if (m->a[i] > m->a[j])
            {
                double tmp = m->a[i];
                m->a[i] = m->a[j];
                m->a[j] = tmp;
            }
        }
    }

    // Invert odd rows
    for (int i = 1; i < m->m; i += 2)
    {
        for (int j = 0; j < m->n / 2; ++j)
        {
            double tmp = m->a[j + i * m->n];
            m->a[j + i * m->n] = m->a[m->n - 1 - j + i * m->n];
            m->a[m->n - 1 - j + i * m->n] = tmp;
        }
    }
}


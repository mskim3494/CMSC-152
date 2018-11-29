/* Min Su Kim, mskim3494 */
/* CMSC 152, Winter 2015 */
/* HOMEWORK 5 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "matrix.h"

matrix *matrix_zero(int n_rows, int n_cols)
{
    int i,j;
    matrix* new= malloc(sizeof(matrix));
    new->n_rows=n_rows;
    new->n_cols=n_cols;
    float** tmp=malloc(n_rows*sizeof(float*));
    for(i=0;i<n_cols;i++){
        tmp[i]=malloc(n_cols*sizeof(float));
    }
    for(i=0;i<n_rows;i++){
        for(j=0;j<n_cols;j++){
            tmp[i][j]=0.0;
        }
    } new->entries=tmp;
    return new;
}

float matrix_read(matrix *m, unsigned int i, unsigned int j)
{
    if(i>=m->n_rows||j>=m->n_cols){
        fprintf(stderr, "out of index");
        exit(1);
    } else {
        return m->entries[i][j];
    }
}

void matrix_write(matrix *m, unsigned int i, unsigned int j, float x)
{
    if(i>=m->n_rows||j>=m->n_cols){
        fprintf(stderr, "out of index");
        exit(1);
    } else {
        m->entries[i][j]=x;
    }
}

matrix *matrix_add(matrix *m, matrix *n)
{
    if(m->n_cols!=n->n_cols||m->n_rows!=n->n_rows){
        fprintf(stderr, "different dimensions");
        exit(1);
    } else {
        int i,j;
        matrix* summed=matrix_zero(m->n_rows, m->n_cols);
        for(i=0;i<m->n_rows;i++){
            for(j=0;j<m->n_cols;j++){
                summed->entries[i][j]=m->entries[i][j] + n->entries[i][j];
            }
        } return summed;
    }
}

matrix *matrix_mult(matrix *m, matrix *n)
{
    if(m->n_cols!=n->n_rows){
        fprintf(stderr, "differing dimensions");
        exit(1);
    } else {
        int i,j,k;
        double acc=0;
        matrix* mult=matrix_zero(m->n_rows,n->n_cols);
        for(i=0;i<m->n_rows;i++){
            for(j=0;j<n->n_cols;j++){
                acc=0.0;
                for(k=0;k<m->n_cols;k++){
                    acc+= m->entries[i][k]*n->entries[k][j];
                } mult->entries[i][j]=acc;
            }
        } return mult;
    }
}

void matrix_show(matrix *m)
{
    int i,j;
    for(i=0;i<m->n_rows;i++){
        for(j=0;j<m->n_cols;j++){
            printf("[%f] ", m->entries[i][j]);
        } printf("\n");
    }
}

void matrix_free(matrix *m)
{
    int i;
    for(i=0;i<m->n_rows;i++){
        free(m->entries[i]);
    }free(m->entries);
    free(m);
}














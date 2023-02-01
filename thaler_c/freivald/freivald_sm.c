/**
 * 
*/
void multiply(
    const int **matrix, 
    const int *vector,
    int *output_vector
){

    int **miter = matrix;
    int sum;

    for(int i = 0; miter[i]; ++i){
        sum = 0;
        for(int j = 0; vector[j]; ++j){
            sum += miter[i][j] * vector[j];
        }
        output_vector[i] = sum;
    }
        
    return output_vector;

}

/**
 * 
*/
int freivald_sm(int **A, int **B){

    // 

    int *abx = mv(A, mv(B, x));

    return 0;

}
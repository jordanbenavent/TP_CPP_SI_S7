#include "SquareMatrix.h"
#include <math.h>

SquareMatrix::SquareMatrix(const Matrix& mat): Matrix(mat){
    if(ncols() != nlines()) throw Bad_Dimensions();
}


double SquareMatrix::det(){
    if(nlines()==2){
        return line(0)[0]*line(1)[1] - line(0)[1]* line(1)[0];
    }
    int deter = 0;
    SquareMatrix result = SquareMatrix(nlines()-1, nlines()-1);
    for (int i= 0; i<ncols(); i++){//ligne avec laquelle on calcul le det
        int subi =0;
        for(int j=1; j<ncols(); j++){ // on récupère les sous-matrice à partir de la ligne 2
            int subj =0;
            for(int k=0; k<nlines(); k++){
                if(k==i) continue;
                result[subi][subj] = line(j)[k];
                subj++;
            }
            subi++;
        }
        deter += (pow(-1,i)*line(0)[i] * result.det());
    }
    return deter;
}
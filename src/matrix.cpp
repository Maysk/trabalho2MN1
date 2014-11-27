#include "../lib/imports.h"

Matrix::Matrix(int height, int width){
    content = new double*[height];
        for(int i=0; i < height; i++){
            content[i] = new double[width];
            for(int j=0; j < width; j++){
                content[i][j] = 0;
            }
    }
}


Matrix::~Matrix(){
    for(int i=0; i < this->height ;i++){
        delete [] content[i];
    }
    delete [] content;
}


bool Matrix::validatePosition(int line, int colunm){
    bool isValid = true;
    if(line<0 || line >= this->height)
        isValid = false;
    if(colunm<0 || colunm>=this->width)
        isValid = false;
    return isValid;
}

void Matrix::setValue(int line, int column, double newValue){
    if(validatePosition(line, column))
        this->content[line][column] = newValue;
}
double Matrix::getValue(int line, int column){
    return this->content[line][column];
}

int Matrix::getHeight(){
    return this->height;
}
int Matrix::getWidth(){
    return this->width;
}
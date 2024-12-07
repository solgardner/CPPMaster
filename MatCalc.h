
#ifndef MATCALC_H
#define MATCALC_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class MatCalc {
  private:
    char Operation;
    int** Array1;
    int A1R;
    int A1C;
    int** Array2;
    int A2R;
    int A2C;
  
  public:
    MatCalc(int** a1,int a1r,int a1c,int** a2,int a2r,int a2c,char oper);
    void MatAdd();
    void MatMul();
    void CreateResultFile(int** result, int rr, int rc);
};
#endif
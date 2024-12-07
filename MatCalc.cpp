#include "MatCalc.h"

MatCalc::MatCalc(int** a1,int a1r,int a1c,int** a2,int a2r,int a2c,char oper) {
      std::cout << "Staring Calculation..." << std::endl;
      Operation = oper;
      Array1 = a1;
      Array2 = a2;
      A1R = a1r;
      A1C = a1c;
      A2R = a2r;
      A2C = a2c;
      
      switch(Operation) {
        case '+':
        std::cout << "Adding" << std::endl;
          MatAdd();
          break;
        //case '-':
          //MatSub();
          //break;
        case '*':
          MatMul();
          break;
        //case '.':
          //MatDot();
          //break;
        default:
          std::cout << "Invalid operand" << std::endl;
          break;
      }
    }
    /*
  void MatCalc::CreateResultFile(int* result, int rr, int rc) { 
    std::string filename = "result.txt"; 
    std::ofstream outFile(filename); 
    if (!outFile) { 
      std::cerr << "Error: Could not open the file." << std::endl; return; 
    } 
    outFile << rr << " " << rc << std::endl; 
    for (int x = 0; x < rr; x++) { 
      for (int y = 0; y < rc; y++) { 
        outFile << *(result + x * rc + y) << " ";
        } 
        outFile << std::endl;
        } 
        outFile.close(); 
        std::cout << "Lines written to " << filename << " successfully." << std::endl;
        }
    */
  void MatCalc::CreateResultFile(int** result,int rr, int rc) {
    std::string filename = "result.txt";
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    // Example data
    std::vector<std::string> lines = {};
    lines.insert(lines.cend(), std::to_string(rr));
    lines.insert(lines.cend(), std::to_string(rc));
    std::string newLine = "";
    for(int x = 0; x < rr; x++) {
       newLine = "";
      for(int y = 0; y < rc; y++) {
        newLine += std::to_string(result[x][y]) + " ";
      }
      lines.insert(lines.cend(), newLine);
    }

    // Write each line to the file
    for (const auto& line : lines) {
        outFile << line << std::endl;
    }

    outFile.close();
    std::cout << "Lines written to " << filename << " successfully." << std::endl;

    return;
  }
  
  
  void MatCalc::MatAdd() {
    if(A1R != A2R || A1C != A2C) {
      std::cout << "Invalid Dimensions" << std::endl;
    }
    int** result = new int*[A1R];
    
    for(int x = 0; x < A1R; x++) {
      result[x] = new int[A1C];
      for (int y = 0; y < A1C; y++) {
        result[x][y] = Array1[x][y] + Array2[x][y];
      }
    }
    CreateResultFile(result,A1R, A1C);
    delete[] result;
  }
  
   void MatCalc::MatMul() {
     std::cout << A1R << "::" << A2C << std::endl;
    if(A1R != A2C) {
      std::cout << "Invalid Dimensions" << std::endl;
    }
    int** result = new int*[A1C];
    /*for(int x = 0; x < A1C; x++) {
      int sum = 0;
      result[x] = new int[A2R];
      for (int y = 0; y < A2R; y++) {
        int* row = Array1[x];
        int* column = new int[A2R];
        for(int i = 0; i < A2R; i++) {
          column[i] = Array2[0][i];
        }
        for(int j = 0; j < A1C; j++) {
          sum += row[j] + column[j];
        }
          result[x][y] = sum;
      }
    }
    */
    /*for(int g = 0; g < A1C; g++) {
      for(int h = 0; h < A2R; h++) {
        std::cout << g << "," << h << ": " << result[h][g];
      }
    }

    CreateResultFile(result,A2C, A1R);
    delete[] result;
    */
  }
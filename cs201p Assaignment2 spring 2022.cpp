#include <iostream>
// Write a class AddMatrix:
// This class should have:
// A two-dimensional array named matrix of integers of dimension 3 x 3.
// A setter method setMatrix() which should assign the passed array to the array matrix.
// It should have two constructors:
//       A default constructor which should initialize the array matrix to zero.
//       A parametrized constructor which should take an array as a parameter
//       and initialize the array matrix with this passed array.
//       (Call the setMatrix() to initialize the array matrix.)
// An overloaded + operator which should take references to two objects of AddMatrix and
// Add the two matrices(arrays) of these two objects.
// Return a reference to the resultant matrix.
// A friend function Multiply() which should take two arguments :
//          A reference to an object of AddMatrix
//          An integer which will be:
//          The FIRST digit of your VU id.
//          Like BC200803333, here 2 is the first digit need to be passed in this function.
//          Multiply this digit with the passed array matrix and
//          Return a reference to this resultant matrix.
// A function display() which could either take a reference to an object of AddMatrix or use this pointer
// To display the  passed matrix.
// In the main() function, you should:
// Make an instance of this class AddMatrix using the following matrix(array).
// {0,1,2,3,0,3,1,2,0}
// Call the friend function Multiply() and pass the above created instance and the FIRST digit of your VU id.
// Add these two matrices (an instance created above and Multiplied matrix) using the overloaded + operator.
// Call the display() function to display the matrix, Multiplied matrix and the resultant(sum) matrix,
using namespace std;

class AddMatrix {
    int matrix[3][3];
public:
    AddMatrix() {
        for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {
            for (int j = 0; j < sizeof(matrix[i]) / sizeof(matrix[i][0]); j++) {
                matrix[i][j] = 0;
            }
        }
    }

    AddMatrix(int matrix[3][3]) {
        setMatrix(matrix);
    }

    void setMatrix(int matrix[3][3]) {
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                AddMatrix::matrix[i][j] = matrix[i][j];
            }
        }
    }

    // Function for addition of two Matrix
    // using operator overloading
    AddMatrix operator+(AddMatrix matrix) {
        // To store the sum of Matrices
        int mat[3][3];

        // Traverse the Matrix x
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Add the corresponding
                // blocks of Matrices
                mat[i][j] = AddMatrix::matrix[i][j]
                            + matrix.matrix[i][j];
            }
        }
        return mat;
    }

    AddMatrix friend Multiply(AddMatrix matrix, int digit) {
        // To store the multiplication
        int mat[3][3];
        // Traverse the Matrix x
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Multiplying each element with the digit
                mat[i][j] = matrix.matrix[i][j] * digit;
            }
        }
        return mat;
    }

    void display(AddMatrix matrix) {
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                cout << matrix.matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int matrix[3][3] = {{0, 1, 2},
                        {3, 0, 3},
                        {1, 2, 0}};
    AddMatrix matrixa(matrix);
    cout<<"Matrix: " << endl;
    matrixa.display(matrixa);

    AddMatrix multipliedMatrix = Multiply(matrixa, 2);
    cout<<"Multiplied by first digit 2: " << endl;
    multipliedMatrix.display(multipliedMatrix);

    AddMatrix sumMatrix = matrixa + multipliedMatrix;
    cout<<"Sum: " << endl;
    sumMatrix.display(sumMatrix);


    return 0;
}

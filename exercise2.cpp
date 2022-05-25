// When does a general linear equation Ax = b has a unique solution of x? How
// to solve it numerically?

#include <iostream>
#include "Eigen/Core"
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;


int main() {
    Matrix<double, 10, 10> A = Matrix<double, 10, 10>::Random();
    Matrix<double, 10, 1> b = Matrix<double, 10, 1>::Random();
    FullPivLU<MatrixXd> Alu_decomp(A);
    auto Arank = Alu_decomp.rank();
    MatrixXd C(A.rows(), A.cols() + b.cols());
    C << A, b;
    FullPivLU<MatrixXd> Clu_decomp(A);
    auto Crank = Clu_decomp.rank();
    cout << "A = [" << A << " ]" << endl;
    cout << "b = [" << b << " ]" << endl;
    if (Arank == Crank) {
        cout << "X = [" << A.colPivHouseholderQr().solve(b)  << " ]"<< endl;
    } else if(Arank < Crank) {
        cout << "There are no solutions" << endl;
    } else {
        cout << "There are many solutions" << endl;
    }

    return 0;
}

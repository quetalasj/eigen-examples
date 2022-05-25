// Suppose there is a large Eigen matrix, we want to know the value in the top
// left 3 × 3 blocks, and then assign it to I 3×3 .

#include <iostream>
#include "Eigen/Core"

using namespace std;
using namespace Eigen;

int main() {
    MatrixXd m = MatrixXd::Random(10, 10);
    cout << m << endl;
    cout << m.topLeftCorner(3, 3) << endl;

    Matrix<double, 3, 3> I = Matrix<double, 3, 3>::Identity();
    cout << I << endl;

    m.topLeftCorner(3, 3) = I;

    cout << m << endl;
    return 0;
}

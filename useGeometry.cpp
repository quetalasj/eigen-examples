#include <iostream>
#include "cmath"
#include "ctime"
#include "Eigen/Core"
#include "Eigen/Dense"
#include "Eigen/Geometry"

using namespace Eigen;
using namespace std;

int main() {
    Matrix3d rotation_matrix = Matrix3d::Identity();

    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1));

    cout.precision(3);

    cout << rotation_vector.matrix() << endl << endl;

    rotation_matrix = rotation_vector.toRotationMatrix();

    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation (by angle axis) = " << v_rotated.transpose() << endl << endl;

    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);

    cout << "yaw pitch roll = " << euler_angles.transpose() << endl << endl;

    Isometry3d T = Isometry3d::Identity();
    T.rotate(rotation_vector);

    T.pretranslate(Vector3d(1, 3, 4));

    cout << "Transform matrix = \n" << T.matrix() << endl << endl;

    Vector3d v_transformed = T * v;
    cout << "v transformed = " << v_transformed.transpose() << endl << endl;

    Quaterniond q = Quaterniond(rotation_vector);
    cout << "quaternion from rotation vector = " << q.coeffs().transpose() << endl << endl;

    q = Quaterniond(rotation_matrix);
    cout << "quaternion from rotation matrix = " << q.coeffs().transpose() << endl << endl;

    // Rotate a vector with a quaternion and use overloaded multiplication
    v_rotated = q * v; // Note that the math is qvq^{−1}
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl << endl;

    cout << "should be equal to " << (q * Quaterniond(0, 1, 0, 0) * q.inverse()).coeffs().transpose() << endl;


}
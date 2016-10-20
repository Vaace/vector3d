#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <ostream>

class vector3d {
private:
    double x,y,z;
    friend vector3d operator*(const vector3d &a, int t);
    friend vector3d operator*(int t, const vector3d &a);
public:
    const static vector3d X;
    const static vector3d Y;
    const static vector3d Z;
    const static vector3d ZERO;

    vector3d() : x(0), y(0), z(0) {}
    vector3d(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    double get_x() const { return x;}
    double get_y() const { return y;}
    double get_z() const { return z;}

    vector3d operator+(const vector3d & t) {return vector3d(get_x()+t.get_x(),get_y()+t.get_y(),get_z()+t.get_z());}

    vector3d operator-(const vector3d & t) {return vector3d(get_x()-t.get_x(),get_y()-t.get_y(),get_z()-t.get_z());}

    vector3d operator-() {return vector3d(-get_x(), -get_y(), -get_z())}

    vector3d operator*(const vector3d, int a) { return vector3d(get_x()*a,get_y()*a,get_z()*a);}

    bool operator==(const vector3d &a) {return (get_x()==a.get_x() && get_y()==a.get_y() && get_z()==a.get_z());}

    bool operator!=(const vector3d &a) {return (!(get_x() == a.get_x() && get_y() == a.get_y() && get_z() == a.get_z()));}

    double getLength() const { return pow((pow(get_x(),2.0)+pow(get_y(),2.0)+pow(get_z(),2.0)),0.5);}

    vector3d normalize() {return (get_x()/getLength(), get_y()/getLength(),get_z()/getLength());}

    vector3d cross( const vector3d &a, const vector3d &b) {
        vector3d result;
        result.get_x() = a.get_y() * b.get_z() - a.get_z() * b.get_y();
        result[1] = a.get_z() * b.get_x() - a.get_x() * b.get_z();
        result[2] = a.get_x() * b.get_y() - a.get_y() * b.get_x();
        return result;
    }

    double scalar( const vector3d &a, const vector3d &b) {
        return (a.get_x()*b.get_x()+a.get_y()*b.get_y()+a.get_z()*b.get_z());
    }


};

friend vector3d operator*(const vector3d &a, int t) { return vector3d::(a.get_x()*t, a.get_y()*t, a.get_z()*t)};
friend vector3d operator*(int t, const vector3d &a) { return vector3d::(a.get_x()*t, a.get_y()*t, a.get_z()*t)};

// TODO: дописать

#endif

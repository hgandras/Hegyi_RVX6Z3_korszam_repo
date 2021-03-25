#include <iostream>
#include <math.h>

using namespace std;

template <typename N>
struct vekt2d
{

    N x, y;

    vekt2d(N a, N b)
    {
        x = a;
        y = b;
    };

    template <typename T>
    auto &operator+=(vekt2d<T> const &b)
    {
        x += b.x;
        y += b.y;
        return *this;
    };

    template <typename T>
    auto &operator-=(vekt2d<T> const &b)
    {
        x -= b.x;
        y -= b.y;
        return *this;
    };

    template <typename T>
    auto &operator*=(T const lambda)
    {
        x = x * lambda;
        y = y * lambda;
        return *this;
    }

    template <typename T>
    auto operator/=(T const lambda)
    {
        x = x / lambda;
        y = y / lambda;
        return *this;
    }

    //template<typename T>
    auto normalize()
    {
        auto norm = (*this);
        x = x / length(norm);
        y = y / length(norm);
        return *this;
    }

    template <typename T>
    auto rotate(T const fi)
    {
        auto rot = (*this);
        x = rot.x * cos(fi) - rot.y * sin(fi);
        y = rot.x * sin(fi) + rot.y * cos(fi);
        return *this;
    }

    template <typename U>
    friend ostream &operator<<(ostream &os, const vekt2d<U> &n);
};

template <typename T, typename U>
auto operator+(vekt2d<T> const &a, vekt2d<U> const &b)
{
    return vekt2d<T>{a.x + b.x, a.y + b.y};
};

template <typename T, typename U>
auto operator-(vekt2d<T> const &a, vekt2d<U> const &b)
{
    return vekt2d<T>{a.x - b.x, a.y - b.y};
};

template <typename T>
ostream &operator<<(ostream &os, const vekt2d<T> &n)
{
    os << "(" << n.x << "," << n.y << ')';
    return os;
};

template <typename T>
istream &operator>>(istream &i, vekt2d<T> &n)
{
    i >> n.x;
    i >> n.y;
    return i;
}

template <typename T, typename U>
auto operator*(U const lambda, vekt2d<T> const &a)
{
    return vekt2d<T>{lambda * a.x, lambda * a.y};
}

template <typename T, typename U>
auto operator*(vekt2d<T> const &a, U const lambda)
{
    return vekt2d<T>{lambda * a.x, lambda * a.y};
}

template <typename T, typename U>
auto operator/(vekt2d<T> const &a, U const lambda)
{
    return vekt2d<T>{a.x / lambda, a.y / lambda};
}

template <typename T>
auto length(vekt2d<T> const &a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

template <typename T, typename U>
auto dot(vekt2d<U> const &a, vekt2d<T> const &b)
{
    return a.x * b.x + a.y * b.y;
}

template <typename T>
auto sqlength(vekt2d<T> const &a)
{
    return a.x * a.x + a.y * a.y;
}



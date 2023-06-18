#include <limits>
#include "stats.h"

Statistician::Statistician() {
    this->reset();
}

void Statistician::next(double r) {
    ++count;
    total += r;
    tinyest = std::min(tinyest, r);
    largest = std::max(largest, r);
}

void Statistician::reset() {
    count = 0;
    total = 0;
    tinyest = std::numeric_limits<double>::infinity();
    largest = -std::numeric_limits<double>::infinity();
}

int Statistician::length() const {
    return count;
}

double Statistician::sum() const {
    return total;
}

double Statistician::mean() const {
    assert(count > 0);
    return total / count;
}

double Statistician::minimum() const {
    assert(count > 0);
    return tinyest;
}

double Statistician::maximum() const {
    assert(count > 0);
    return largest;
}

Statistician operator+(const Statistician &lhs, const Statistician &rhs) {
    Statistician new_stat;
    new_stat.count = lhs.count + rhs.count;
    new_stat.total = lhs.total + rhs.total;
    new_stat.tinyest = std::min(lhs.tinyest, rhs.tinyest);
    new_stat.largest = std::max(lhs.largest, rhs.largest);

    return new_stat;
}

Statistician operator*(double scalar, const Statistician &stat) {
    Statistician new_stat;
    new_stat.count = stat.count;
    new_stat.total = stat.total * scalar;
    new_stat.tinyest = (scalar >= 0 ? stat.tinyest : stat.largest) * scalar;
    new_stat.largest = (scalar >= 0 ? stat.largest : stat.tinyest) * scalar;

    return new_stat;
}

bool operator==(const Statistician &lhs, const Statistician &rhs) {
    if (lhs.length() == 0 && rhs.length() == 0) {
        return true;
    }

    return lhs.length() == rhs.length()
           && lhs.mean() == rhs.mean()
           && lhs.sum() == rhs.sum()
           && lhs.minimum() == rhs.minimum()
           && lhs.maximum() == rhs.maximum();
}

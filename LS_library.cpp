/*
	v 0.1
*/
#include <vector>
#include <numeric>
#include <cmath>
#include "LS_library.h";

double average(std::vector<int>& vect) {
	auto const count = static_cast<float>(vect.size());
	return std::accumulate(vect.begin(), vect.end(), 0.0) / count;
}

double st_dev(std::vector<int>& vect) {
	const double avg = average(vect);
	auto const count = static_cast<float>(vect.size());
	double sum = 0.0;
	for (const auto& v : vect) {
		sum += (v - avg) * (v - avg);
	}
	return std::sqrt(sum / count);
}

double st_dev(std::vector<int>& vect, double avg) {
	auto const count = static_cast<float>(vect.size());
	double sum = 0.0;
	for (const auto& v : vect) {
		sum += (v - avg) * (v - avg);
	}
	return std::sqrt(sum / count);
}
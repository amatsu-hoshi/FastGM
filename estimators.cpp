#include"estimators.h"
#include<iostream>
double JpEstimator::estimate_by_sketch(std::vector<int> s1, std::vector<int> s2) const
{
	return std::inner_product(s1.begin(), s1.end(), s2.begin(), 0.,
		std::plus<>(), [](int a, int b) -> double {return a == b ? 1. : 0.; }) / s1.size();
}
double JpEstimator::estimate_brute_force(std::vector<double> v1, std::vector<double> v2) const
{
	double j_p = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		double t = 0.;
		for (int j = 0; j < v1.size(); j++)
		{
			t += std::max(v1[j] / v1[i], v2[j] / v2[i]);
		}
		j_p += 1. / t;
	}
	return j_p;
}
double LambdaEstimator::estimate_by_sketch(std::vector<double> y) const
{
	double G_m = std::accumulate(y.begin(), y.end(), 0.);
	return (y.size() - 1.) / G_m;
}
double LambdaEstimator::estimate_brute_force(std::vector<double> v) const
{
	return std::accumulate(v.begin(), v.end(), 0.);
}
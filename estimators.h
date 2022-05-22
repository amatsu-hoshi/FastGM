#include<vector>
#include<algorithm>
#include<numeric>
class JpEstimator
{
public:
	JpEstimator() = default;
	double estimate_by_sketch(std::vector<int> s1, std::vector<int> s2) const;
	double estimate_brute_force(std::vector<double> v1, std::vector<double> v2) const;
};
class LambdaEstimator
{
public:
	LambdaEstimator() = default;
	double estimate_by_sketch(std::vector<double> s) const;
	double estimate_brute_force(std::vector<double> v) const;
};
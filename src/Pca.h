/**
 * Eigen header file 
 */

#include <vector>
#include "../Eigen/Dense"

#ifndef _Pca_H
#define _Pca_H

class Pca {

	public:
	double mean_january, mean_july;
	Eigen::Matrix<double, 2, 2> covarianceMatrix;
	double total_variance; // total variance of components
	double component1_eigenvalue, component2_eigenvalue; // eigenvalues of components

	Pca(); // constructor
	// ~Eigen(); // destructor

	// calculate eigenValues for the principal components 1 and 2
	std::string EigenValues();

	// construct eigenvectors for the principal components 1 and 2
	Eigen::MatrixXd EighenVectors() const;

	// calculate values for covariance matrix
	Eigen::Matrix<double, 2, 2> ComputeCovariance(const std::vector<double> &january, const std::vector<double> &july);

	// calculate total variance
	std::string TotalVariance();

	// calculate proportion of total variance
	std::string ProportionVariance() const;

	// subtract mean from each of the data dimensions.
	std::vector<double> AdjustData(const std::vector<double> &dataset) const;

	// calculate the mean of data in dataset
	double mean(const std::vector<double> &dataset) const;

};

#endif


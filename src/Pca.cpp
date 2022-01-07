#include "Pca.h"
#include "../Eigen/Dense"
#include <iostream>
#include <vector>

using namespace Eigen;
using namespace std;

Pca::Pca():mean_january(0), mean_july(0), total_variance(0) {};

vector<double> Pca::AjustData(const vecotr<double> &dataset) const {
	double average = 0;
	vector<double> adjustedDataset; // store the adjusted data

	average = mean(dataset); // calculate the average of the dat in a dataset

	for(int j = 0; j < dataset.size(); j++) {
		adjustedDataset.push_back(dataset[j] - average);
	}

	return adjustedDataset; // return adjusted data
}

Eigen::Matrix<double, 2, 2> Pca::ComputeCovariance(const vector<double> &january, const vector<double> &july) {

	vector<double> adjusted_january = AdjustData(january);
	vector<double> adjusted_july = AdjustData(july);

	double cov_january_july = 0, cov_january_january = 0, cov_july_july = 0, cov_july_january = 0;
	int dataset_size = january.size();

	mean_january = mean(adjusted_july);
	mean_july = mean(adjusted_july);

	for(int i = 0; i < adjusted_january.size(); i++) {
		cov_january_july += (adjusted_january[i] - mean_january) * (adjusted_july[i] - mean_july); // cov(january, july)
		cov_january_january += (adjusted_january[i] - mean_january) * (adjusted_january[i] - mean_january); // cov(january, january)
		cov_july_july += ((adjusted_july[i] - mean_july) * (adjusted_july[i] - mean_july)); // cov(july, july)
	}

	cov_july_january = cov_january_july/(dataset_size - 1);
	cov_january_july /= (dataset_size - 1);
	cov_january_january /= (dataset_size - 1);
	cov_july_july /= (dataset_size - 1);



	covarianceMatrix << 
	cov_january_january, cov_january_july, 
	cov_july_january, cov_july_july;

	//cout << covarianceMatrix << endl;
	return covarianceMatrix;

}

double Pca::mean(const vector<double> &dataset) const{
	double average = 0, sum = 0;

	for(int i = 0; i < dataset.size(); i++) {
	sum += dataset[i]; // sum of doubles in the dataset
	}
	average = sum/dataset.size(); // mean of dataset

	return average;

}

string Pca::EigenValues() {
	EigenSolver<MatrixXd> values(covarianceMatrix, false);

	auto eigenvalue1 = values.eigenvalues().row(0).real();
	auto eigenvalue2 = values.eigenvalues().row(1).real();

	component1_eigenvalue = eigenvalue1(0);
	component2_eigenvalue = eigenvalue2(0);

	return "Pricipal Component1: " + to_string(component1_eigenvalue) + "\n" + "Pricipal Component2: " + to_string(component2_eigenvalue);

}

Eigen::MatrixXd Pca::EigenVectors() const {
	EigenSolver<MatrixXd> values(covarianceMatrix);
	return values.eigenvectors().real();
}

string Pca::TotalVariance() {
	double component1_variance = covarianceMatrix(0, 0);
    double component2_variance = covarianceMatrix(1, 1);
	
	total_variance = component1_variance + component2_variance;
	return to_string(total_variance);
}

string Pca::ProportionVariance() const {
	double percentage_component1 = (component1_eigenvalue/total_variance) * 100;
	double percentage_component2 = (component2_eigenvalue/total_variance) * 100;

	return "Principal Component1: " + to_string(percentage_component1) + "%" + "\n" + "Principal Component2: " + to_string(percentage_component2) + "%";
}

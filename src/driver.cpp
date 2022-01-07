#include "Pca.h"
#include "Values.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "../Eigen/Dense"

using namespace std;

int main(int argc, char *argv[]) {
	string filename = "output.txt"; // default filename output
	Pca pca;
	ofstream outputfile;

	if (argc > 1) {
		filename = string(argv[1]); // filename provided
		cout << filename << endl;
	}

	Eigen::Matrix<double, 2, 2> covarianceMatrix = pca.ComputeCovariance(january, july);

	outputfile.open(filename); // open file

	cout << "Writing output...." << endl;

	outputfile << "1. What are the Eigenvalues for the principal components 1 and 2?" << endl << endl; 
	outputfile << pca.EigenValues() << endl << endl;

	outputfile << "2. What are the Eigenvectors for the principal components 1 and 2 (showingJuly and January component values for each)?" << endl << endl;
	outputfile << pca.EigenVectors() << endl << endl;

	outputfile << "3. Compute the values for the covariance matrix." << endl << endl;
	outputfile << covarianceMatrix << endl << endl;

	outputfile << "4. What is the total variance?" << endl << endl;
	outputfile << pca.TotalVariance() << endl << endl;

	outputfile << "5. What proportion (as a percentage) of total variance do principal compo-nents 1 and 2 ""explain""?" << endl << endl;
	outputfile << pca.ProportionVariance()<< endl << endl;
	
	outputfile.close(); // close file

	cout << "Output written to " + filename  << endl;


}
---------------------------------------------------------------------------------------------------------------------------------------------
			Principal Component Analysis (PCA)
---------------------------------------------------------------------------------------------------------------------------------------------
Date: 17/05/2020
Student Number: BGNDEE001

Description:
Applying a PCA algorithm to a dataset containing average rainfall (mm) in July and January.

Driver file:
Pca implementation: Pca.cpp, Pca.h
dataset: Values.hpp

File functionality:
- driver.cpp: The driver file that output results to a file.
- Values.hpp: contains the dataset
- Pca.cpp: calculates eigenvalues, covariance matrix, eigenvectors.

Makefile includes:
- a compile run that compiles and links the project (default)
- a clean rule that removes both the object code(.o) files and the "driver" executable

Run instructions:
- open terminal
- navigate to the directory "principla_component_analysis" and run the command "make"
- input the following command
	
	./pca [outputfile]

where the argument [outputfile] is an optional argument

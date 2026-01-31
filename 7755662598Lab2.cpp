#include <iostream>
#include <fstream>
using namespace std;

// Build matrix class
class Matrix { 

	public: 
		// These are the attrubutes
		int value[10][10];
		int target_row_idx;
		int minimum;
		int maximum;	
	
	
		// This is the constructor
		Matrix() {
			target_row_idx = -1;
			minimum = 0;
			maximum = 0;
	
		}
	
		// Method to read the data in the .txt files
		void readFile(string filename) {
			// Opening the file and storing it as matrixFile
			fstream matrixFile(filename);

			// Loop through the file and put the data in the array I defined earlier
 			for (int i = 0; i < 10; i++) {
        		for (int j = 0; j < 10; j++) {
                	matrixFile >> value[i][j];
            	}
    		}

			// Have to close the file at the end
			matrixFile.close();
		}
	
	// This function just figures out the 
	void linear_search() {
		// First number
		int FirstNum = value[0][0];

		// Start with an impossible index
		target_row_idx = -1;

		// Start the loops
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				// skip the first element
				if (i == 0 && j == 0) {
					// continue is used to skip but not break the loop
					continue;
				}

				if (value[i][j] == FirstNum) {
					target_row_idx = i;
					// end the search
					return;
				}
			}
		}
	}

	// Function to find min and max
	void max_min_search() {
		// initialize max/min to first number
		maximum = value[0][0];
		minimum = value[0][0];

		// Loop through
		for (int i = 0; i < 10; i++) {
        	for (int j = 0; j < 10; j++) {
				// if the new value is greater than the current max, update
            	if (value[i][j] > maximum) {
                	maximum = value[i][j];
				}
				// if the new value is less than the current min, update
            	if (value[i][j] < minimum) {
					minimum = value[i][j];
				}
        	}
    	}
	}

	// Function to send Q1 to files
	void write_Q1_file(string filename) {
		// Run the searches functions
		linear_search();
    	max_min_search();

		ofstream outputFile(filename);

		// Write that dashed line
		outputFile << "-------------------------------------------------------------------------------" << "\n\n";

		if (target_row_idx != -1) {
        	outputFile << "Target value in matrix is shown in row " << target_row_idx << "\n\n";
    	} 	
		else {
        	outputFile << "Target value in matrix is not shown\n\n";
    	}


		outputFile << "Maximum value is " << maximum << "\n\n";
    	outputFile << "Minimum value is " << minimum << "\n\n";

		// Another dashed line
		outputFile << "-------------------------------------------------------------------------------" << "\n\n";

		outputFile.close();
	}


	// Define the matrix addition function for Q2
	Matrix mat_add(Matrix other_mat) {
		Matrix sum;

		// Use another loop for element wise addition
		for (int i = 0; i < 10; i++) {
        	for (int j = 0; j < 10; j++) {
            	sum.value[i][j] = value[i][j] + other_mat.value[i][j];
        	}
    	}

    	return sum;

	}

	// Define function to write Q2 file
	void write_Q2_Q3_file(string filename) {
		ofstream outputFile(filename);

		// Write that dashed line
		outputFile << "-------------------------------------------------------------------------------" << "\n\n";

		// Put in the matrix seperated by a line for each row and a space for each entry in the row
		for (int i = 0; i < 10; i++) {
        	for (int j = 0; j < 10; j++) {
            	outputFile << value[i][j] << " ";
        	}
        	outputFile << "\n\n";
    	}

		// Another dashed line
		outputFile << "-------------------------------------------------------------------------------" << "\n\n";
	
		// Close file
		outputFile.close();
	}

	Matrix mat_mul(Matrix other_mat) {
		Matrix prod;

		// loop through i and j
		for (int i = 0; i < 10; i++) {
        	for (int j = 0; j < 10; j++) {
				// initially set the element to 0 before calculating it with a sum over r elements
				prod.value[i][j] = 0;
            	for (int r = 0; r < 10; r++) {
                	prod.value[i][j] += value[i][r] * other_mat.value[r][j];
            	}
        	}
    	}

		return prod;
	}


};


int main() {
	// Create two matrix objects
    Matrix matrix1, matrix2;

	// use the read file function for the matrix objects to put in the values
    matrix1.readFile("matrix_1.txt");
    matrix2.readFile("matrix_2.txt");

	// Write the Q1 files
	matrix1.write_Q1_file("output_Q1_1.txt");
	matrix2.write_Q1_file("output_Q1_2.txt");

	// Write the Q2 file
	Matrix sum;
	sum = matrix1.mat_add(matrix2);
	sum.write_Q2_Q3_file("output_Q2.txt");
    
	// Write the Q3 file
	Matrix prod;
	prod = matrix1.mat_mul(matrix2);
	prod.write_Q2_Q3_file("output_Q3.txt");

    return 0;
	
}

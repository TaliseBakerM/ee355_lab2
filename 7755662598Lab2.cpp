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
            	if (value[i][j] > maximum) {
                	maximum = value[i][j];
				}
            	if (value[i][j] < minimum) {
					minimum = value[i][j];
				}
        	}
    	}
	}

	// Function to send Q1 to files
	void writeQ1File(string outputfile) {
		// Run the searches functions
		linear_search();
    	max_min_search();

		ofstream resultFile(outputfile);

		// Write that dashed line
		resultFile << "-------------------------------------------------------------------------------" << "\n\n";

		if (target_row_idx != -1) {
        	resultFile << "Target value in matrix is shown in row " << target_row_idx << "\n\n";
    	} 	
		else {
        	resultFile << "Target value in matrix is not shown\n\n";
    	}


		resultFile << "Maximum value is " << maximum << "\n\n";
    	resultFile << "Minimum value is " << minimum << "\n\n";

		// Another dashed line
		resultFile << "-------------------------------------------------------------------------------" << "\n\n";

		resultFile.close();

	}



};


int main() {
	cout << "start";
	// Create two matrix objects
    Matrix matrix1, matrix2;

	// use the read file function for the matrix objects to put in the values
    matrix1.readFile("matrix_1.txt");
    matrix2.readFile("matrix_2.txt");

	cout << "Done w this";

	// Write the Q1 files
	matrix1.writeQ1File("output_Q1_1.txt");
	matrix2.writeQ1File("output_Q1_2.txt");

	cout << "Done";
    

    return 0;
}

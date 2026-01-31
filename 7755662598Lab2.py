import numpy as np
import pickle

# Start by defining functions similar to the ones in the matrix object in c++
def read_matrix(filename):
    # This file reads in the matrix from the text files and returns a numpy array
    matrix = np.loadtxt(filename, dtype=int)
    return matrix

# Replicates the linear_search function, needs to take in the matrix
def linear_search(matrix):
    # Find first number
    firstNum = matrix[0][0]

   # loop through with two loops up to i = 10 cause each matrix is 10 by 10
    for i in range(10):
        for j in range(10):
            # Skipping the first row, looking for a match and returning if it was found
            if matrix[i, j] == firstNum and not (i == 0 and j == 0): 
                return i
    
    # This case it was not found so we return -1 to symbolize not being found (like idx = -1 from c++ code)
    return -1

# Function to replace max_min_search from c++
def max_min_search(matrix):
    # Start with the max and min defined as the first element
    maximum = matrix[0, 0]
    minimum = matrix[0, 0]

    # Loop through the matrix and change the max and min if a greater or lower number are found
    for i in range(10):
        for j in range(10):
            if matrix[i, j] > maximum:
                maximum = matrix[i, j]

            if matrix[i, j] < minimum:
                minimum = matrix[i, j]

    # Return the max and min
    return maximum, minimum


# Replacing the mat_add function, but this time takes in two matrices
def mat_add(matrix1, matrix2):
    # Define an empy array
    sum = np.zeros((10, 10), dtype=int)

    # loop through for element wise addition
    for i in range(10):
        for j in range(10):
            sum[i, j] = matrix1[i, j] + matrix2[i, j]

    # return the result matrix
    return sum

# Replacing the mat_mul function
def mat_mul(matrix1, matrix2):
    # Define an empty array
    prod = np.zeros((10, 10), dtype=int)


    for i in range(10):
        for j in range(10):
            for r in range(10):
                prod[i, j] += matrix1[i, r] * matrix2[r, j]

    # Return the matrix
    return prod


# Now, call all the functions and use the pickle files

# Read in matrices
matrix1 = read_matrix("matrix_1.txt")
matrix2 = read_matrix("matrix_2.txt")

# Solve the linear search and max, min calculations
idx_row_mat_1 = linear_search(matrix1)
idx_row_mat_2 = linear_search(matrix2)
max_mat_1, min_mat_1 = max_min_search(matrix1)
max_mat_2, min_mat_2 = max_min_search(matrix2)

# Calculate the matrix addition
matrix_add = mat_add(matrix1, matrix2)

# Calculate the matrix multiplication
matrix_mul = mat_mul(matrix1, matrix2)


# Put them in the pickel file
data = {
    'idx_row_mat_1': idx_row_mat_1,
    'max_mat_1': max_mat_1,
    'min_mat_1': min_mat_1,
    'idx_row_mat_2': idx_row_mat_2,
    'max_mat_2': max_mat_2,
    'min_mat_2': min_mat_2,
    'mat_add': matrix_add,
    'mat_mul': matrix_mul
}

with open('output_py.pickle', 'wb') as f:
    pickle.dump(data, f)


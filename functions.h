#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "eigen\Eigen\Sparse"
#include "eigen\Eigen\Dense"
#include "GF2.hpp"
#include <typeinfo>
#include <utility>
#include <filesystem>


Eigen::SparseMatrix<GF2> read_matrix(const std::string& file_name, const int& H_rows, const int& H_cols)
{
    if (!std::filesystem::exists(file_name)) {
        throw std::runtime_error("File does not exist: " + file_name);
    }

    std::ifstream file(file_name);
    file.clear();
    file.seekg(0);
    std::string line;
    Eigen::SparseMatrix<GF2> H(H_rows, H_cols);
    int H_col{};

    

    for (int i{}; i < H_rows; i++) {
        H_col = 0;
        std::getline(file, line);
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            H.insert(i, H_col) = GF2(number);
            H_col += 1;
        }
    }

    return H;
}


std::pair<Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic>,
          Eigen::VectorX<GF2>> H_to_codeword(const std::string& file_matrix_H,
                                                  const Eigen::VectorX<GF2>& bits_message,
                                                  const int& H_rows, const int& H_cols)
{
    Eigen::SparseMatrix<GF2> H {read_matrix(file_matrix_H, H_rows, H_cols)};
    Eigen::SparseMatrix<GF2> H_transposed = H.transpose();

    const int G_cols{ H_cols };
    const int G_rows{ H_cols - H_rows };
    Eigen::SparseMatrix<GF2> G_matrix(G_rows, G_cols);

    Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> identity_matrix(G_rows, G_rows);
    identity_matrix.setIdentity();

    Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> dense_G_matrix = G_matrix.toDense();
	dense_G_matrix.block(0, 0, G_rows, G_rows) = identity_matrix;

    Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> dense_H_transposed = H_transposed.toDense();

    dense_G_matrix.block(0, G_rows, G_rows, H_rows) = dense_H_transposed.block(0,0,G_rows, H_rows);

    Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> dense_codeword = bits_message.transpose() * dense_G_matrix;

    Eigen::VectorX<GF2> codeword(dense_codeword.size());
    for (int i = 0; i < dense_codeword.rows(); ++i) {
        for (int j = 0; j < dense_codeword.cols(); ++j) {
            codeword(i * dense_codeword.cols() + j) = dense_codeword(i, j);
        }
    }
    return std::make_pair(dense_G_matrix, codeword);
}

Eigen::VectorX<GF2> checking_syndrome(const Eigen::VectorX<GF2>& codeword,
                                           const std::string& file_matrix_H,
                                           const int& H_rows, const int& H_cols)
{
    Eigen::SparseMatrix<GF2> H {read_matrix(file_matrix_H, H_rows, H_cols)};

    Eigen::SparseMatrix<GF2> H_transposed = H.transpose();

    Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> zero_maxtrix_vec = codeword.transpose() * H_transposed;

    Eigen::VectorX<GF2> zero_vector (zero_maxtrix_vec.size());
    for (int i = 0; i < zero_maxtrix_vec.rows(); ++i) {
        for (int j = 0; j < zero_maxtrix_vec.cols(); ++j) {
            zero_vector(i * zero_maxtrix_vec.cols() + j) = zero_maxtrix_vec(i, j);
        }
    }
    return zero_vector;
}

#endif FUNCTIONS_H
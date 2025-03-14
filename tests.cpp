#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "external/doctest/doctest.h"
#include "functions.h"

TEST_CASE("Checking the incorrect file's name"){
    CHECK_THROWS_WITH(read_matrix("bad_file_name.txt", 10, 15), "File does not exist: bad_file_name.txt");
}

TEST_CASE("Checking the correctness of the formation of the G matrix"){
    Eigen::SparseMatrix<GF2> test_G_matrix{read_matrix("test_data.txt", 10, 15)};
    std::string H_file{"matrix_data.txt"};
    int H_rows{5};
    int H_cols{15};

    Eigen::VectorX<GF2> vector_message_bits(10);
    vector_message_bits << GF2(1), GF2(0), GF2(0), GF2(1), GF2(0), GF2(1), GF2(1), GF2(0), GF2(1), GF2(0);

    Eigen::VectorX<GF2> codeword{};
    Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> G_matrix{};
    std::tie(G_matrix, codeword) = H_to_codeword(H_file, vector_message_bits, H_rows, H_cols);
    bool cheking_1 = true;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (test_G_matrix.coeff(i, j) != G_matrix(i, j)){
                cheking_1 = false;
                break;
            }
        if (cheking_1 == false){
            break;
        }
        }   
    }
    CHECK(cheking_1);
}


TEST_CASE("Checking the size of the matrices and the syndrome for all 10-bit-vectors") {
    std::string H_file{"matrix_data.txt"};
    int H_rows{5};
    int H_cols{15};
    for (int message_value = 0; message_value < (1 << 10); ++message_value) {
        Eigen::VectorX<GF2> vector_message_bits(10);
        for (int i = 0; i < 10; ++i) {
            vector_message_bits(i) = GF2((message_value >> (9 - i)) & 1);
        }

        Eigen::VectorX<GF2> codeword{};
        Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> G_matrix{};
        std::tie(G_matrix, codeword) = H_to_codeword(H_file, vector_message_bits, H_rows, H_cols);
        Eigen::VectorX<GF2> zero_vector = checking_syndrome(codeword, H_file, H_rows, H_cols);

        CHECK(G_matrix.rows() == H_cols - H_rows);
        CHECK(G_matrix.cols() == H_cols);
        CHECK(zero_vector.cols() == 1);
        CHECK(zero_vector.rows() == H_rows);

        Eigen::VectorX<GF2> expected_zero_vector = Eigen::VectorX<GF2>::Zero(zero_vector.size());

        CHECK(zero_vector == expected_zero_vector);
    }
}
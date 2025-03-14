#include "functions.h"
#include "eigen\Eigen\Sparse"
#include "eigen\Eigen\Dense"

int main()
{
	std::string H_file{"matrix_data.txt"};
	int H_rows{5};
	int H_cols{15};

	Eigen::VectorX<GF2> vector_message_bits(10);
	vector_message_bits << GF2(1), GF2(0), GF2(0), GF2(1), GF2(0), GF2(1), GF2(1), GF2(0), GF2(1), GF2(0);

	Eigen::VectorX<GF2> codeword{};
	Eigen::Matrix<GF2, Eigen::Dynamic, Eigen::Dynamic> G_matrix{};
	std::tie(G_matrix, codeword) = H_to_codeword(H_file, vector_message_bits, H_rows, H_cols);
	Eigen::VectorX<GF2> zero_vector = checking_syndrome(codeword, H_file, H_rows, H_cols);

	std::cout << "G_matrix" << std::endl << G_matrix << std::endl 
			  << "codeword" << std::endl << codeword.transpose() << std::endl
			  << "zero_vector" << std::endl << zero_vector.transpose() << std::endl;

	return 0;
}
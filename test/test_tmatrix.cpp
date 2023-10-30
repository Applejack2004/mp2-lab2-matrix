#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(3);
	for (int i = 0; i < m1.GetSize(); i++)
    for (int j = 0; i < m1.GetSize(); i++)
	{
		m1[i][j] = 1;
	}
	TMatrix<int> m2(m1);

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int>* m1 = new TMatrix<int>[2];
	m1[0][0] = 1;
	m1[0][1] = 3;
	m1[1][0] = 30;
	m1[1][1] = 30;
	TMatrix<int> m2(*m1);
	delete[] m1;
	EXPECT_EQ(2, m2.GetSize());
	EXPECT_EQ(1, m2[0][0]);
	EXPECT_EQ(3, m2[0][1]);
	EXPECT_EQ(30, m2[1][0]);
	EXPECT_EQ(30, m2[1][1]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  ADD_FAILURE();
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  ADD_FAILURE();
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  ADD_FAILURE();
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  ADD_FAILURE();
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  ADD_FAILURE();
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  ADD_FAILURE();
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  ADD_FAILURE();
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  ADD_FAILURE();
}


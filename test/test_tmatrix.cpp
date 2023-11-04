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
	TMatrix<int> m1(5);
    TMatrix<int> m2(m1);

	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int>* m1 = new TMatrix<int>(2);

	TMatrix<int> m2;
	for (int i = 0; i < 2; i++)
		for (int j = i; j < 2; j++)
		{
			(*m1)[i][j] = 1;
		}
	m2 = *m1;
	delete m1;


	EXPECT_EQ(1, m2[0][0]);
	EXPECT_EQ(1, m2[0][1]);
	EXPECT_EQ(1, m2[1][1]);

	
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m[0][0] = 5);
	EXPECT_EQ(m[0][0], 5);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][-3] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[100][100] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(12);
	ASSERT_NO_THROW(m=m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(12);
	TMatrix<int> m2(12);
	ASSERT_NO_THROW(m2 = m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	TMatrix<int> m2(12);
	m = m2;
	EXPECT_NE(5, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(2);
	TMatrix<int> m2(12);
	ASSERT_NO_THROW(m2 = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(2);
	//TMatrix<int> m2(2);
	for (int i = 0; i < 2; i++)
		for (int j = i; j < 2; j++)
		{
			m[i][j] = 1;
		}

	TMatrix<int> m2(m);
	//m2[0][0] = 1;
	//m2[0][1] = 1;
	//m2[1][0] = 1;
	//m2[1][1] = 1;
	
	EXPECT_EQ(1, m == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(3);
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
		{
			m[i][j] = 1;
		}
	EXPECT_EQ(1, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(1);
	TMatrix<int> m2(2);
	EXPECT_EQ(1, m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	ASSERT_NO_THROW(m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(1);
	TMatrix<int> m2(2);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(2);
	ASSERT_NO_THROW(m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(1);
	TMatrix<int> m2(2);
	ASSERT_ANY_THROW(m1 - m2);
}


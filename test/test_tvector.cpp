#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v1(3);
	for (int i = 0; i < v1.GetSize(); i++)
	{
		v1[i] = 1;
	}
	TVector<int> v2(v1);

  EXPECT_EQ(v1, v2);
}

  TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(3);

	TVector<int> v2(v1);
	EXPECT_NE(v1.Get_pVector(), v2.Get_pVector());
	/* 
	TVector<int>* v1= new TVector<int>(3);
	(*v1)[0] = 1;
	(*v1)[1] = 3;
	(*v1)[2] = 30;
	TVector<int> v2(*v1);
	delete [] v1;
	EXPECT_EQ(3,v2.GetSize());
	EXPECT_EQ(1,v2[0]);
	EXPECT_EQ(3,v2[1]);
	EXPECT_EQ(30,v2[2]);
	*/

}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(10);
	ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(10,1);
	//v[100000] = 1;
	ASSERT_ANY_THROW(v[100000] = 1);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(10);
	ASSERT_NO_THROW(v=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(10);
	TVector<int> v1(10);
	v[0] = 1000;
	v1 = v;
	EXPECT_EQ(v1, v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(8);
	TVector<int> v1(10);
	
	v1 = v;
	EXPECT_EQ(v1.GetSize(), v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(3);
	v[0] = 30;
	v[1] = 300;
	v[2] = 121234;
	TVector<int> v1(10);

	v1 = v;
	EXPECT_EQ(v1, v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(3);
	v[0] = 1;
	v[1] = 3;
	v[2] = 30;
	TVector<int> v1(3);
    v1 = v;
	EXPECT_EQ(v1, v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(3);
	v[0] = 1;
	v[1] = 3;
	v[2] = 30;
	EXPECT_EQ(v, v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(3);
	TVector<int> v1(13);
	EXPECT_NE(v, v1);
}


TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(3);
	for (int i = 0; i < 3; i++)
	{
		v[i] = 3;
	}
	v = v + 1;
	EXPECT_EQ(v[0], 4);
	EXPECT_EQ(v[1], 4);
	EXPECT_EQ(v[2], 4);
  
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
	{
		v[i] = 3;
		v1[i] = 1;
     }
	ASSERT_NO_THROW( v - 2);
	v = v - 2;
	EXPECT_EQ(v1, v);

}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3);
	v[0] = 1;
	v[1] = 1;
	v[2] = 1;

	v = v * 123;
	EXPECT_EQ(v[0], 123);
	EXPECT_EQ(v[1], 123);
	EXPECT_EQ(v[2], 123);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(3);
	v[0] = 3;
	v[1] = 2;
	v[2] = 1;

	TVector<int> v1(v);
	v = v + v1;
	EXPECT_EQ(v[0], 6);
	EXPECT_EQ(v[1], 4);
	EXPECT_EQ(v[2], 2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(45);
	ASSERT_ANY_THROW(v + v1);
}
	

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(3);
	v[0] = 1;
	v[1] = 1;
	v[2] = 1;

	TVector<int> v1(v);
	v = v - v1;
	EXPECT_EQ(v[0], 0);
	EXPECT_EQ(v[1], 0);
	EXPECT_EQ(v[2], 0);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(45);
	ASSERT_ANY_THROW(v - v1);

}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
	{
		v[i] = 2;
		v1[i] = 3;
	}
	int a = v1 * v;
	EXPECT_EQ(a, 18);


	ASSERT_NO_THROW(v1 * v);

}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(3);
	TVector<int> v1(45);
	ASSERT_ANY_THROW(v * v1);
}


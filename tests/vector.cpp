#include "../includes/tests.hpp"

static void default_constructor(void)
{
	print_header("Default constructor");
	ft::vector<int> v1;
	std::vector<int> v2;
	check("v1 == v2", v1 == v2);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("v1 == v2", v1 == v2);
}

static void copy_constructor(void)
{
	print_header("Copy");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft::vector<int> v3(v1);
	std::vector<int> v4(v2);
	v1.push_back(42);
	v2.push_back(42);
	check("v1 == v2", (v1 == v2));
	check("v3 == v4", (v3 == v4));
	check("v2 != v4", (v2 != v4));
	// check("v1 != v3", (v1 != v3));
}

void	test_vector(void)
{
	print_header("Vector");

	default_constructor();
	copy_constructor();
}

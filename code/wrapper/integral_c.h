#pragma once
struct integral_c_tag { constexpr static int value = 0; };
//tag for integral_c
template<class T, T N>
struct integral_c
{
	static constexpr T value = N;
	using tag = integral_c_tag;
	using type = integral_c<T, N>;
	using value_type = decltype(N);
	using next = integral_c<T, N + 1>;
	using prior = integral_c<T, N - 1>;
	constexpr operator T()const { return N; }
};
//implement for integral_c
template<bool C>
struct bool_
{
	static const bool value = C;
	using tag=integral_c_tag;
	using type = bool_<C>;
	using value_type = bool;
	constexpr operator bool()const { return C; }
};
//implement for bool_
	
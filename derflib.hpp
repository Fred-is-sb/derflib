//DerfLIB V1.9.1 patch 0
/*遵循CC-BY-SA协议开源，请勿滥用*/
/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

 // 17.4.1.2 Headers

 // C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#ifndef derflib
#define derflib



namespace noi
{
	long long ls_prime(long long x)
	{
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0) return x/i;
		}
		abort();
	}

	void move(int n, char A, char B, char C, int y) {      //n代表现在需要将第n个圆盘放到目标位置C
		if (n == 1)                                 //当递归到第1个圆盘时，直接将其放到目标位置C
			if(y == n)
			std::cout << A << "->" << C << std::endl;
		else {
			move(n - 1, A, C, B, y);    //1.将n-1层圆盘放到辅助位置B
			//2.对于第n-1个圆盘，把B当作目标位置，C当作辅助位置，所以BC互换
			std::cout << A << "->" << C << std::endl;         //将第n个圆盘放到目标位置C上
			move(n - 1, B, A, C, y);         //1.将n-1层圆盘放到目标位置C
			//2.对于n-2层圆盘，A当作辅助位置，B当作开始位置，所以AB互换
		}
	}

}
_STD_BEGIN
	bool fxxk_u_stdio() {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}
	vector<int> olasieve(int n) {
		vector<int> prime;
		bool IsPrime[n];
		int cnt = 0;
	
		memset(IsPrime, true, sizeof(IsPrime));
	
		for (int i = 2; i <= n; i++) {
			if (IsPrime[i]) {
				prime.push_back(i); cnt++; // 2, 3, 5
	
				for (int j = 0; j < cnt; j++) {      //遍历质数表
					if (i * prime[j] > n) break;      //如果超过最大范围，跳出
					IsPrime[i * prime[j]] = false;    //将以prime[j]]为最小质因数的合数筛掉
					if (i % prime[j] == 0) break; //保证只筛到以prime[j]为最小质因数的数
				}
			}
			return prime;
		}
	}
	// 求出从2到N的所有素数
	vector<int> ishsieve(int N) {
		vector<int> primes;  // 用于存储所有素数
		vector<bool> is_prime(N + 1, true);  // 用于记录每个整数是否为素数
	
		// 从2开始，依次枚举每个整数
		for (int i = 2; i <= N; i++) {
			// 如果这个数没有被标记为非素数，则将它加入素数列表
			if (is_prime[i]) {
				primes.push_back(i);
			}
			// 将这个数的倍数从数组中去除
			for (int j = i * i; j <= N; j += i) {
				is_prime[j] = false;
			}
		}

		return primes;
	}
	bool is_prime(long long x)
	{
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0) return 0;
		}
		return 1;
	}
	long long a(long long upper, long long lower)
	{
		long long ans = 1;
		for (int i = 0; i < upper; i++)
		{
			ans *= lower - i;
		}
		return ans;
	}
	long long c(long long upper, long long lower)
	{
		long long ans = a(upper, lower);
		for (int i = upper; i >= 1; i--)
		{
			ans /= i;
		}
		return ans;
	}
	//非递归快速幂（有待研究）
	int qpow(int a, int n) {
		int ans = 1;
		while (n) {
			if (n & 1)        //如果n的当前末位为1
				ans *= a;  //ans乘上当前的a
			a *= a;        //a自乘
			n >>= 1;       //n往右移一位
		}
		return ans;
	}
	long long fibo(int n) {
		return n == 1 || n == 2?1:fibo(n - 1) + fibo(n - 2);
	}
	_STD_END
#endif // !derflib 


//gives answer in 32-bits
string decToBin(int n)
{
	string s = "";
	while (n)
	{
		s.pb(n % 2 + 48);
		n /= 2;
	}

	while (s.length() < 32)
		s.pb('0');

	reverse(s.begin(), s.end());
	return s;
}

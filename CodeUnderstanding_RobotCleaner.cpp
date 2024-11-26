int ConvertInt(char * t)
{
	return (t[0] - '0') * 10 + (t[1] - '0');
}

int ComputeTime(void)
{
	int s = ConvertInt(start_time) * 60 + ConvertInt(start_time + 3);
	int e = ConvertInt(end_time) * 60 + ConvertInt(end_time + 3);
	if(s>e) {
		s = (s -720);
		e = e+720;
		return (e - s);
	}
	return (e - s);
}

int Solve(void)
{
	int p;
	int t = ComputeTime();
	// cout << t << "\n";


	if (t < 30) return 500;
	if ((t - 30) % 10 == 0)
	p = 500 + ((int)((t - 30) / 10)) * 300;
	else
	p = 500 + ((int)((t - 30) / 10) + 1) * 300;
	
	if (p >= 30000) p = 30000;

	return p;
}

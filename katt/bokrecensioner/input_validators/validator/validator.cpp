#include "validator.h"

void run() {
	int n = Int(1, int(1e5));
	Space();
	int m = Int(1, int(1e5));
	Space();
	int r = Int(1, int(5e5));
	Endl();

	vector<string> allowed_relation = {};
	string allowed = Arg("allowed");
	if (allowed=="less") allowed_relation = {"<"};
	else if (allowed=="equal_and_less") allowed_relation = {"<","="};
	else if (allowed=="all") allowed_relation = {"<","=","<="};
	else assert(0);
	
	for (int i = 0; i < r; i++)
	{
		stringstream s(Line());
		int a, b;
		string rel;
		s >> a >> rel >> b;
		assert(1 <= a && a <= n);
		assert(1 <= b && b <= n);
		
		assert(find(allowed_relation.begin(),allowed_relation.end(), rel)!=allowed_relation.end());
	}

	Eof();
}

#include "VectorVert.h"

int VectorVert::output(const string FileName)
{
	ofstream fout(FileName, ios_base::app);
	for (auto i = v.begin(); i != v.end(); ++i) {
		fout << *i << '\n';
	}
	fout << '\n';
	fout.close();
	return 0;
}


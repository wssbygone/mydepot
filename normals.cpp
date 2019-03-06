#include<iostream>
#include<fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <ctype.h>

using namespace std;
struct data
{
	double x;
	double y;
	double z;
};

int cnt=0;

int main(int argc, char** argv)  
{
    std::ifstream fin;
    std::ofstream fout;
	std::cout<<"["<<argv[1]<<"]"<<std::endl;
    fin.open(argv[1]);
	double input;
    if (fin.fail())
    {
        std::cout << "open input file failed"<< std::endl;
        return false;
    }
	while (!fin.eof())
    {		
		fin>>input;
		std::cout << fixed << setprecision(6)<<input;
		cnt++;
		if( 0 == cnt%3 )
		{
			std::cout<<endl;
		}
		else
		{
			std::cout<<"  ";
		}
        if (fin.bad() == true || fin.fail() == true)
        {
            fin.close();
            std::cout << "read file failed" << std::endl;
            return false;
        }		
	}
	
	return 0;
}


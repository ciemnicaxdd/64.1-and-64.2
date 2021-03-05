#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class klasa
{

	ifstream plik1;
	ofstream plik2;
	vector <string> tablica;


	public:


		klasa();
		void check_on_this();
		bool explore_whether();

};

klasa::klasa()
{
	plik1.open("plik1.txt");
	plik2.open("plik2.txt");
}

void klasa::check_on_this()

{
int number_of_lines=0;

int numbers_of_operations=0;
string one_of_the_sentences;
	  string empty_or_not;
	if(plik1.good())
        {
		while(!plik1.eof())
		{
			number_of_lines++;
			plik1>>one_of_the_sentences;


			tablica.push_back(one_of_the_sentences);
			if(number_of_lines==20)

            {
        if(this->explore_whether())

				{
            numbers_of_operations++;
        }
				number_of_lines=0;
				tablica.clear();

				        plik1>>empty_or_not;
			}
		}
	}
	cout<<numbers_of_operations;
}

bool klasa::explore_whether()

{
	vector <string> try_another_array;
	for(int i=0; i<tablica.size()/2; i++)

        {

		string first_one = tablica[i].substr(0, tablica[i].length()/2);


		string second_one = tablica[i].substr(tablica[i].length()/2, tablica[i].length()/2);

		if(first_one!=second_one)

		{
			return false;}
    try_another_array.push_back(first_one);
	}
	int j=0;
for(int i=tablica.size()/2; i<tablica.size(); i++)

	{
		string third_one = tablica[i].substr(0, tablica[i].length()/2);

string fourth_one = tablica[i].substr(tablica[i].length()/2, tablica[i].length()/2);

		if(third_one!=try_another_array[j] || fourth_one!=try_another_array[j])

		{
        return false;
		}
		j++;
		}
	return true;
}



int main(int argc, char** argv)
{
	klasa t1;
	t1.check_on_this();

	return 0;
}

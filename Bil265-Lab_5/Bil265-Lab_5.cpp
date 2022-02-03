#include<iostream>
#include<string.h>
#include<list>
#include<fstream>
#include<string>
#include<vector>
#include"d_search.h"
#include"d_util.h"

using namespace std;

struct ogrenci {
	string num;
	string name;
};

int main()
{
	ifstream file("Lab5.txt", ios::in);
	string ikinokta = ":";
	string satir;
	size_t pos = 0;
	string token;
	int count = 0;
	ogrenci ogr;
	list<struct ogrenci> devam;
	vector<string> bilgiler;
	vector<struct ogrenci>devam2;

	if (!file) {
		cout << "error";
	}
	
	while (getline(file, satir)) {
		while ((pos = satir.find(":")) != string::npos) {//npos means not found 
			token = satir.substr(0, pos);
			//cout << token << endl;
			satir.erase(0, pos + ikinokta.length());
		}
		bilgiler.push_back(satir);
		count++;
	}

	string tok2;

	for (int i = 0;i < count;i++) {

		//cout << bilgiler[i]<<"\n";
		if ((pos = bilgiler[i].find("2")) == string::npos) {
			continue;

		}
		else {
			while ((pos = bilgiler[i].find("2")) != string::npos) {//npos means not found 
				tok2 = bilgiler[i].substr(pos, pos + 8);
				ogr.num = tok2;
				ogr.name = bilgiler[i].erase(pos, pos + 8);
			}
			devam.push_back(ogr);
		}

	}

	list<struct ogrenci>::iterator iter;
	list<struct ogrenci>::iterator iterend;
	list<struct ogrenci>::iterator tmp;

	iter = devam.begin();
	iterend = devam.end();
	iterend--;
	tmp = iter;
	tmp++;

	while (iter != iterend) {
		while (tmp != iterend) {

			if (tmp->num == iter->num) {
				devam.erase(tmp);
			}
			tmp++;
		}
		iter++;
	}


	ofstream fileptr("YoklamaListesi.txt", ios::out);

	writeList(devam);
	//cout << satir << "\n";


}

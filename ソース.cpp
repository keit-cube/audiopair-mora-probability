#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

#define TEXTNAME "./audio_string_keit.txt"

string one_mora = "BA DA FA GA HA JA KA LA MA NA PA SA TA YA ZA BE CE DE FE GE JE KE LE ME NE PE SE TE ZE AH BH CH DH FH GH IH KH LH MH NH OH PH RH SH TH UH ZH BI CI DI FI GI HI KI MI NI OI PI RI SI UI ZI BO CO DO FO GO HO JO KO MO NO PO RO SO TO YO ZO BU DU FU GU HU JU KU LU MU NU OU PU SU TU YU ZU BY CY DY GY HY KY LY MY NY PY SY TY";
//string one_mora = "BA CA DA FA GA HA JA KA LA MA NA PA RA SA TA YA ZA BY CY DY GY HY KY LY MY NY PY SY TY AH BH CH DH EH FH GH IH KH MH NH OH PH RH SH TH UH ZH BE CE DE FE GE HE JE KE LE ME NE PE SE TE YE ZE BO CO DO FO GO HO JO KO LO MO NO PO RO SO TO YO ZO BI CI DI FI GI HI KI MI NI PI RI SI TI ZI BU CU DU FU GU HU JU KU LU MU NU OU PU SU TU ZU";



int main() {

	ifstream ifs(TEXTNAME);
	string str;
	int num = 0;
	int one_mora_count_all = 0;
	int mora_sum_all = 0;
	int str_letter_all = 0;
	int mora_distribution[7] = {};

	if (ifs.fail()) {
		cerr<<"Failed to open file."<<endl;
		return -1;
	}
	while (getline(ifs, str)) {
		num++;
		string str_copy;
		string cout_disp = "";
		vector<string> str_pair;
		vector<int> mora_count;
		int mora_sum = 0;
		int one_mora_count = 0;

		str_copy = str;

		if (str.size() % 2 == 1) {
			cout << num << "行目が奇数です。" << endl;
			return -1;
		}

		while (str_copy.size() > 0) {
			str_pair.push_back(str_copy.substr(0,2));
			str_copy.erase(0, 2);
		}

		cout << setw(3) << right << num << ":" << setw(12) << left << str;
		cout << " -----> ";
		for (int i = 0; i < str_pair.size(); i++) {
			if (one_mora.rfind(str_pair[i]) == string::npos)
				mora_count.push_back(2);
			else {
				mora_count.push_back(1);
				one_mora_count++;
			}

			//cout << str_pair[i] <<":"<<mora_count[i] << " ";
			cout_disp += str_pair[i] + ":" + to_string(mora_count[i]) + " ";
			mora_sum += mora_count[i];
		}
		cout << setw(30) << left << cout_disp;
		cout << "-----> " << setw(2) << right << mora_sum << " mora" << endl;
		//cout << one_mora_count << endl;
		mora_distribution[one_mora_count]++;
		one_mora_count_all += one_mora_count;
		mora_sum_all+=mora_sum;
		str_letter_all += str.size();

	}

	cout << endl << endl;
	cout <<num<<"ソルブ合計:" << mora_sum_all << " mora, " << str_letter_all << " letter" << endl;
	cout << "1moraペアが出現した数: " << one_mora_count_all << ", 1ソルブあたり " << setprecision(2) << double(one_mora_count_all) / double(num) << " 回出現" << endl;
	cout << "1moraペアがx回出現したソルブ数  ";
	for (int i = 0; i < 7; i++) {
		cout << i << "回: " << mora_distribution[i] << ", ";
	}
	cout << endl;
	cout << "音削減率: " << setprecision(4) << 100 - double(mora_sum_all) / double(str_letter_all) * 100 << "%" << endl;

	return 0;
}
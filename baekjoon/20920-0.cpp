#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void addIndex(vector<char*>& str, vector<int>& strIndex, char* temp);
void printStr(vector<char*>& str, vector<int>& strIndex);
void addStr(vector<char*>& str, char* temp);
void swapIdx(int& idx1, int& idx2);
void swapStr(char*& p1, char*& p2);

int main(void) {
	int n, m;
	cin >> n >> m;
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	vector<char*> str;
	vector<int> strIndex;
	//���ڿ� �Է� �޽��ϴ�.
	while (n--) {
		char* temp = new char[11];
		cin >> temp;
		cin.tie(NULL);
		cin.sync_with_stdio(false);
		//���ڿ� ���̰� m���� ũ�ų� ������ str �迭�� �߰��մϴ�.
		if (strlen(temp) >= m) {
			addStr(str, temp);
			addIndex(str,strIndex, temp);
		}
	}

	//����մϴ�.
	//���� ������ �ܾ ���� ����մϴ�.
	printStr(str, strIndex);

	for (int i{ 0 }; i < str.size(); i++)
		delete[] str[i];
	return 0;
}
void addStr(vector<char*>& str, char* temp) {
	bool pass = true;
	if (str.size() == 0) {
		str.push_back(temp);
	}
	for (int i{ 0 }; i < str.size(); i++)
		if (str[i] == temp) {
			pass = false;
			break;
		}
	if (pass)
		str.push_back(temp);
}
void addIndex(vector<char*>& str,vector<int>& strIndex, char* temp) {
	for (int i{ 0 }; i < str.size(); i++) {
		//�ߺ��� �˻��ϰ� �����ϸ� 1 �����մϴ�.
		if (temp == str[i]) //������ ���ڿ� �ּҰ� ������ �ߺ��Դϴ�.
			strIndex[i] += 1;
		//���ο� ���ڿ��̸� strIndex 1 �����մϴ�.
		else 
			strIndex.push_back(1);
	}
}

void printStr(vector<char*>& str, vector<int>& strIndex) {
	//���� ������ �ܾ ���� ��ġ�մϴ�.
	//���� ���ķ� ū��
	for (int i{ 0 }; i < strIndex.size() - 1; i++)
		for (int j{ 0 }; j < strIndex.size() - 1 - i; j++)
			if (strIndex[j] < strIndex[j + 1]) {
				swapStr(str[j], str[j + 1]);
				swapIdx(strIndex[j], strIndex[j + 1]);
			}
	for (int i{ 0 }; i < str.size() - 1; i++) {
		if (strIndex[i] > strIndex[i + 1]) {
			cout << str[i] << "\n";
		}
		else if (strIndex[i] == strIndex[i + 1]) {
			if (strlen(str[i]) > strlen(str[i+1])) {
				cout << str[i] << "\n";
			}
			else if (strlen(str[i]) == strlen(str[i + 1])) {
				if (strcmp(str[i], str[i + 1]) < 0) {
					cout << str[i] << "\n";
				}
				else
					cout << str[i + 1] << "\n";
			}
		}
	}
}

void swapIdx(int& idx1, int& idx2) {
	int temp = idx1;
	idx1 = idx2;
	idx2 = idx1;
}
void swapStr(char*& p1, char*& p2) {
	char* temp = p1;
	p1 = p2;
	p2 = temp;
}
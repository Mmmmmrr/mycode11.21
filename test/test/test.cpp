#define _CRT_SECURE_NO_WARNINGS 1
//����ͳ��
//������һ������Ȼ����������飬���շ���ͳ�Ƴ��ִ��������
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--){
		int m;
		cin >> m;
		map<int, map<int, int>> mp;
		int num[100];
		int team[100];
		for (int i = 0; i<m; i++){
			cin >> num[i];
		}
		for (int i = 0; i<m; i++){
			cin >> team[i];
		}
		for (int i = 0; i<m; i++){
			mp[team[i]][num[i]]++;
		}
		for (int i = 0; i<m; i++){
			for (auto it = mp.begin(); it != mp.end(); it++){
				map<int, int>::iterator tmp = it->second.find(num[i]);
				if (tmp == it->second.end()){
					it->second[num[i]] = 0;
				}
			}//���������û�����������Ӳ�����Ϊ0
		}
		for (auto i = mp.begin(); i != mp.end(); i++){
			cout << i->first << "={";
			bool flag = false;
			for (auto j = i->second.begin(); j != i->second.end(); j++){
				if (flag == false){
					cout << j->first << "=" << j->second;
					flag = true;
				}
				else{
					cout << "," << j->first << "=" << j->second;
				}
			}
			cout << "}" << endl;
		}
	}
	return 0;
}


//�����ַ���
//�������ַ������������4 ���ַ�����Ҫ���������ַ�������ǰ�棬����
//���룺EricZ
//�����1 = EricZ
//���룺David
//�����1 = David 2 = EricZ
//���룺Peter
//�����1 = Peter 2 = David 3 = EricZ
//���룺Alan
//�����1 = Alan 2 = Peter 3 = David 4 = EricZ
//���룺Jane
//�����1 = Jane 2 = Alan 3 = Peter 4 = David
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int m;
	cin >> m;
	getchar();
	vector<string> v;
	for (int i = 0; i < m; i++)
	{
		string str;
		getline(cin, str);
		v.push_back(str);
		int cnt = 0;   //������¼���������
		for (int j = v.size() - 1; j >= 0; j--)
		{
			cnt++;
			if (cnt < 5)
			{
				printf("%d=%s%s", cnt, v[j].c_str(), (j == 0 || cnt == 4 ? "\n" : " "));
			}
		}
	}
	return 0;
}
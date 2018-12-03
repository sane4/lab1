#include "Note.h"
const int size1 = 8;//������
Note notes[size1];//������ ������
int j, n = size1;
void Sort(int j, int n) {
	do {
		
		int nn = 0;
		for (j = 1; j < n; ++j)
			if (notes[j - 1].Day() > notes[j].Day()
				&& notes[j - 1].Month() > notes[j].Month()
				&& notes[j - 1].Year() > notes[j].Year()) {
				Note temp = notes[j - 1];
				notes[j - 1] = notes[j];
				notes[j] = temp;
				nn = j;
			}
		n = nn;
	} while (n);

}
int main(){
	string phone;
	setlocale(LC_ALL, "");
	int choice;
	while(true){
		 cout << "\n1. �������\n2. �����\n3. ��������\n4. �����\n-> ";
		 cin >> choice;
		 switch(choice){
		 case 1:
			 cout << "��� ������� ������� DD MM YY\n";
			 try{
				 //��������� ������
				for(int i = 0; i < size1; ++i){
				   cin >> notes[i];
				}
				/*���������*/
				Sort(j, n);
			 }
			 catch(const Exception& e){
				cout << "\n" << e.what();
			 }
			 break;
		 case 2:
			 cout << "������� ����� ��������: ";
			 
			 cin >> phone;
			 int i;
			 for(i = 0; i < size1; ++i){
				if(notes[i].Phone() == phone){
					cout << "\n" << notes[i];
				}
			 }
			 if(i > size1){
				cout << "NOT FOUND";
			 }
			 break;
		 case 3:
			 int index;
			 do{
				cout << "������� ������: ";
				cin >> index;
			 } while(index < 0 || index >= 8);//������ �� ������������� �����
			 cout << "��� ������� ������� DD MM YY\n";
			 cin >> notes[index];
			 break;
		 case 4:
			 return 0;
			 break;
		 }
	}
}
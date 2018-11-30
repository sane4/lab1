#include "Note.h"

int main(){
	const int size = 8;//������
	setlocale(LC_ALL, "");
	Note notes[size];//������ ������
	int choice;
	while(true){
		 cout << "\n1. �������\n2. �����\n3. ��������\n4. �����\n-> ";
		 cin >> choice;
		 if(choice == 1){
			 cout << "��� ������� ������� DD MM YY\n";
			 try{
				 //��������� ������
				for(int i = 0; i < size; ++i){
				   cin >> notes[i];
				}
				/*���������*/
				int j, n = size;
				do {
					int nn = 0;
					for (j = 1; j < n; ++j)
						if (notes[j-1].Day() > notes[j].Day() 
							&& notes[j-1].Month() > notes[j].Month()
							&& notes[j-1].Year() > notes[j].Year()) {
							Note temp = notes[j-1];
							notes[j-1] = notes[j];
							notes[j] = temp;
							nn = j;
						}
						n = nn;
				} while (n);
			 }
			 catch(const Exception& e){
				cout << "\n" << e.what();
			 }
		 }
		 else if(choice == 2){
			 cout << "������� ����� ��������: ";
			 string phone;
			 cin >> phone;
			 int i;
			 for(i = 0; i < size; ++i){
				if(notes[i].Phone() == phone){
					cout << "\n" << notes[i];
				}
			 }
			 if(i > phone){
				cout << "NOT FOUND";
			 }
		 }
		 else if(choice == 3){
			 int index;
			 do{
				cout << "������� ������: ";
				cin >> index;
			 } while(index < 0 || index >= 8);//������ �� ������������� �����
			 cout << "��� ������� ������� DD MM YY\n";
			 cin >> notes[index];
		 }
		 else if(choice == 4){
			 return 0;
		 }
	}
}
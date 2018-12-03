#include "Note.h"
const int size1 = 8;//размер
Note notes[size1];//массив знаков
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
		 cout << "\n1. Считать\n2. Поиск\n3. Изменить\n4. Выход\n-> ";
		 cin >> choice;
		 switch(choice){
		 case 1:
			 cout << "Имя Фамилия Телефон DD MM YY\n";
			 try{
				 //считываем данные
				for(int i = 0; i < size1; ++i){
				   cin >> notes[i];
				}
				/*Сортируем*/
				Sort(j, n);
			 }
			 catch(const Exception& e){
				cout << "\n" << e.what();
			 }
			 break;
		 case 2:
			 cout << "Введите номер телефона: ";
			 
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
				cout << "Введите индекс: ";
				cin >> index;
			 } while(index < 0 || index >= 8);//защита от некорректного ввода
			 cout << "Имя Фамилия Телефон DD MM YY\n";
			 cin >> notes[index];
			 break;
		 case 4:
			 return 0;
			 break;
		 }
	}
}
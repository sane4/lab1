#include "Note.h"

int main(){
	const int size = 8;//размер
	setlocale(LC_ALL, "");
	Note notes[size];//Массив знаков
	int choice;
	while(true){
		 cout << "\n1. Считать\n2. Поиск\n3. Изменить\n4. Выход\n-> ";
		 cin >> choice;
		 if(choice == 1){
			 cout << "Имя Фамилия Телефон DD MM YY\n";
			 try{
				 //считываем данные
				for(int i = 0; i < size; ++i){
				   cin >> notes[i];
				}
				/*Сортируем*/
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
			 cout << "Введите номер телефона: ";
			 string phone;
			 cin >> phone;
			 int i;
			 for(i = 0; i < size; ++i){
				if(notes[i].Phone() == phone){
					cout << "\n" << notes[i];
				}
			 }
			 if(i > size){
				cout << "NOT FOUND";
			 }
		 }
		 else if(choice == 3){
			 int index;
			 do{
				cout << "Введите индекс: ";
				cin >> index;
			 } while(index < 0 || index >= 8);//защита от некорректного ввода
			 cout << "Имя Фамилия Телефон DD MM YY\n";
			 cin >> notes[index];
		 }
		 else if(choice == 4){
			 return 0;
		 }
	}
}

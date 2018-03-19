#include <ctime>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
const int M=536; //ЧИСЛО ГОРОДОВ
using namespace std;
typedef struct gorod{
   string name;
   int god;
   int naselenie;
};
void siftDown(int *numbers, int root, int bottom,int &srav,int &pers)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done))
  {
    srav++;
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2]>numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root]< numbers[maxChild])
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
      pers++;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
void siftDownG(gorod *numbers, int root, int bottom,int &srav,int &pers)
{
  time_t start, end;
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done))
  {
    srav++;
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2].god>numbers[root * 2 + 1].god)
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root].god < numbers[maxChild].god)
    {
      gorod temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
      pers++;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
void siftDownN(gorod *numbers, int root, int bottom,int &srav,int &pers)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done))
  {
    srav++;
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2].naselenie>numbers[root * 2 + 1].naselenie)
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root].naselenie < numbers[maxChild].naselenie)
    {
      gorod temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
      pers++;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size, int &srav,int&pers)
{
  time_t start, end;
  start = clock();
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--){
    siftDown(numbers, i, array_size,srav,pers);}
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1,srav,pers);
  }
  end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя Пирамидальной сортировки = " << seconds;
  cout<<"\nКоличество: Сравнений: "<<srav<<"  Перестановок: "<<pers;
  srav=0; pers=0;
}
void heapSortG(gorod *numbers, int array_size,int &srav,int&pers)
{
    time_t start, end;
    start = clock();
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--){
    siftDownG(numbers, i, array_size,srav,pers);}
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    gorod temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDownG(numbers, 0, i - 1,srav,pers);
  }
  end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя сортировки по году = " << seconds;
}

void heapSortN(gorod *numbers, int array_size,int &srav,int&pers)
{
    time_t start, end;
    start = clock();
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--){
    siftDownN(numbers, i, array_size,srav,pers);}
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    gorod temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDownN(numbers, 0, i - 1,srav,pers);
  }
  end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\n\nВремя сортировки по населению = " << seconds;
}
void quickSort(int *a ,int l, int r, int &srav, int&pers)
{
   int w,x,i,j;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j){
       while (a[i]<x) i++;
       while (x<a[j]) j--;
       srav++;
       if (i<=j){
         w=a[i];
         a[i]=a[j];
         a[j]=w;
         i++;
         j--;
         pers++;
       }
   }
   if (l<j) quickSort(a,l,j,srav,pers);
   if (i<r) quickSort(a,i,r,srav,pers);
}

void quickSortG(gorod *a ,int l, int r, int &srav, int&pers)
{
    time_t start, end;
   gorod w;
   int x,i,j;
   start = clock();
   i=l;
   j=r;
   x=a[(l+r)/2].god;
   while (i<=j){
       while (a[i].god<x) i++;
       while (x<a[j].god) j--;
       srav++;
       if (i<=j){
         pers++;
         w=a[i];
         a[i]=a[j];
         a[j]=w;
         i++;
         j--;
       }
   }
   if (l<j) quickSortG(a,l,j,srav,pers);
   if (i<r) quickSortG(a,i,r,srav,pers);
}
void quickSortN(gorod *a ,int l, int r, int &srav, int&pers)
{
    time_t start, end;
   gorod w;
   int x,i,j;
   start = clock();
   i=l;
   j=r;
   x=a[(l+r)/2].naselenie;
   while (i<=j){
       while (a[i].naselenie<x) i++;
       while (x<a[j].naselenie) j--;
       srav++;
       if (i<=j){
         pers++;
         w=a[i];
         a[i]=a[j];
         a[j]=w;
         i++;
         j--;
       }
   }
   if (l<j) quickSortN(a,l,j,srav,pers);
   if (i<r) quickSortN(a,i,r,srav,pers);
}


void BubSort(int *arr, int col, int &srav, int&pers) {
    time_t start, end;
    int trash=0;
    start = clock();
    for (int i=1; i<=col ; i++)
    {
        for (int j=1; j<=col-i; j++)
        {
            srav++;
            if (arr[j]>arr[j+1])
            {
                trash=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=trash;
                pers++;
            }
        }
    }
  end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя Сортировки Пузырьком = " << seconds;
  cout<<"\nКоличество: Сравнений: "<<srav<<"  Перестановок: "<<pers;
  srav=0; pers=0;
}
void BubSortG(gorod *arr, int col, int &srav, int&pers) {
    gorod trash;
    time_t start, end;
    start = clock();
    for (int i=0; i<col-1 ; i++)
    {
        for (int j=i+1; j<col; j++)
        {
            srav++;
            if (arr[i].god>arr[j].god)
            {
                pers++;
                trash=arr[i];
                arr[i]=arr[j];
                arr[j]=trash;
            }
        }
    }
    end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nВремя сортировки по году = " << seconds;
}
void BubSortN(gorod *arr, int col, int &srav, int&pers) {
    gorod trash;
    time_t start, end;
    start = clock();
    for (int i=0; i<col-1 ; i++)
    {
        for (int j=i+1; j<col; j++)
        {
            srav++;
            if (arr[i].naselenie>arr[j].naselenie)
            {
                pers++;
                trash=arr[i];
                arr[i]=arr[j];
                arr[j]=trash;
            }
        }
    }
    end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\n\nВремя сортировки по населению = " << seconds;
}

void Swap(int *Mas, int i)
{
   int temp;
   temp=Mas[i];
   Mas[i]=Mas[i-1];
   Mas[i-1]=temp;
}
void SwapG(gorod *Mas, int i)
{
   gorod temp;
   temp=Mas[i];
   Mas[i]=Mas[i-1];
   Mas[i-1]=temp;
}
void SwapN(gorod *Mas, int i)
{
   gorod temp;
   temp=Mas[i];
   Mas[i]=Mas[i-1];
   Mas[i-1]=temp;
}
void ShakerSort(int *Mas, int Start, int N, int &srav, int&pers)
{
    time_t start, end;
   int Left, Right, i;
   Left=Start;
   Right=N-1;
   start = clock();
   while (Left<=Right){
      for (i=Right; i>=Left; i--){
        srav++;
        if (Mas[i-1]>Mas[i]){
                Swap(Mas, i);
                pers++;
        }
      }
      Left++;
      for (i=Left; i<=Right; i++){
        srav++;
        if (Mas[i-1]>Mas[i]){
            Swap(Mas, i);
            pers++;
        }
      }
      Right--;
  }
  end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя Шейкерной сортировки = " << seconds;
  cout<<"\nКоличество: Сравнений: "<<srav<<"  Перестановок: "<<pers;
  srav=0; pers=0;
}
void ShakerSortG(gorod *Mas, int Start, int N, int &srav, int&pers)
{
   time_t start, end;
   int Left, Right, i;
   Left=Start;
   Right=N-1;
   start = clock();
   while (Left<=Right){
      for (i=Right; i>=Left; i--){
        srav++;
        if (Mas[i-1].god>Mas[i].god){
            SwapG(Mas, i);
            pers++;
        }
      }
      Left++;
      for (i=Left; i<=Right; i++){
        srav++;
        if (Mas[i-1].god>Mas[i].god){
            SwapG(Mas, i);
            pers++;
        }
      }
      Right--;
   }
  end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\nВремя сортировки по году = " << seconds;
}
void ShakerSortN(gorod *Mas, int Start, int N, int &srav, int&pers)
{
    time_t start, end;
   int Left, Right, i;
   Left=Start;
   Right=N-1;
   start = clock();
   while (Left<=Right){
      for (i=Right; i>=Left; i--){
        srav++;
        if (Mas[i-1].naselenie>Mas[i].naselenie){
            SwapN(Mas, i);
            pers++;}
      }
      Left++;
      for (i=Left; i<=Right; i++){
        srav++;
        if (Mas[i-1].naselenie>Mas[i].naselenie){
            SwapN(Mas, i);
            pers++;
        }
      }
        Right--;
    }
    end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "\n\nВремя сортировки по населению = " << seconds;
}

void SortBestCase(int *a, int n)
{
	int i, j, k, temp;
	for(i = n/2; i > 0; i = i/2)
	{
		for(j = i; j < n; j++)
		{
			for(k = j-i; k >= 0; k = k-i)
			{
				if(a[k+i] >= a[k])
				break;

				else
				{
					temp = a[k];
					a[k] = a[k+i];
					a[k+i] = temp;
				}
			}
		}
	}
}
void reverse(int *a, int n){
	for (int i  = 0; i < n / 2; i++)
 swap(a[i], a[n - i - 1]);
}
int main(){
label1:
	int a;
	int pers=0, srav=0;
	setlocale(LC_ALL,"Russian");
	int choice;
	cout << "\nСортировка\n1. База данных(Города)\n2. Массив чисел\n";
	cin >> choice;
	switch (choice){
	case 1:{
		ifstream fin;
		ofstream fout1;
		ofstream fout2;
		fout1.open("GorodaSortedGod.txt");
		fout2.open("GorodaSortedNaselenie.txt");
		fin.open("Goroda.txt");
		struct gorod g[M];
		for(int i=0;i<M;++i){
		   fin >> g[i].name>> g[i].naselenie >> g[i].god;
		}
		int choice2;
		system("cls");
		cout << "\n1. Пирамидальная сортировка\n2. Быстрая сортировка\n3. Сортировка пузырьком\n4. Шейкерная сортировка\n";
		cin >> choice2;
		if(choice2==1){
			heapSortG(g,M,srav,pers);
			cout<<"\nГода: Сравнений: "<<srav<<"  Перестановок: "<<pers;
			srav=0,pers=0;
			for(int i=0;i<M;++i){
				fout1 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
			heapSortN(g,M,srav,pers);
			cout<<"\nНаселение: Сравнений: "<<srav<<"  Перестановок: "<<pers;
			srav=0,pers=0;
			for(int i=0;i<M;++i){
				fout2 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
		}
		else if(choice2==2){
			quickSortG(g,0,M-1,srav,pers);
			cout<<"\nГода: Сравнений: "<<srav<<"  Перестановок: "<<pers;
            srav=0,pers=0;
			for(int i=0;i<M;++i){
				fout1 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
			quickSortN(g,0,M-1,srav,pers);
			cout<<"\nНаселение: Сравнений: "<<srav<<"  Перестановок: "<<pers;
            srav=0,pers=0;
			for(int i=0;i<M;++i){
				fout2 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
		}
		else if(choice2==3){
			BubSortG(g,M,srav,pers);
			cout<<"\nГода: Сравнений: "<<srav<<"  Перестановок: "<<pers;
			srav=0,pers=0;
			for(int i=0;i<M;++i){
				fout1 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
				}
			BubSortN(g,M,srav,pers);
			cout<<"\nНаселение: Сравнений: "<<srav<<"  Перестановок: "<<pers;
			srav=0,pers=0;
			for(int i=0;i<M;++i){
				fout2 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
		}
		else if(choice2==4){
			ShakerSortG(g,1,M,srav,pers);
			for(int i=0;i<M;++i){
				fout1 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
				}
            cout<<"\nГода: Сравнений: "<<srav<<"  Перестановок: "<<pers;
            srav=0,pers=0;
			ShakerSortN(g,1,M,srav,pers);
			for(int i=0;i<M;++i){
				fout2 <<  g[i].name <<"   "<< g[i].naselenie << "   "<< g[i].god << "\n";
			}
			cout<<"\nНаселение: Сравнений: "<<srav<<"  Перестановок: "<<pers;
			srav=0,pers=0;
		}
		fout1.close();
		fout2.close();
		fin.close();
		break;
		   }
    case 2:{
		time_t start, end;
		srand(time(NULL));
		int N,slu;
		cout << "\nВведите размер массива: ";
		cin >> N;
		int *a1=new int[N];
		cout << "\n1. Средний случай \n2. Худший случай \n3. Лучший случай\n";
		cin >> slu;
		if(slu==1){
		  for(int i=0;i<N;++i){
		    a1[i]=rand()%101;
		  }
          heapSort(a1,N,srav,pers);


		  for(int i=0;i<N;++i){
		    a1[i]=rand()%101;
		  }
          start = clock();
		  quickSort(a1,0,N-1,srav,pers);
          end = clock();
          double seconds = (double)(end - start) / CLOCKS_PER_SEC;
          cout << "\nВремя Быстрой сортировки = " << seconds;
          cout<<"\nКоличество: Сравнений: "<<srav<<"  Перестановок: "<<pers;
          srav=0; pers=0;

		  for(int i=0;i<N;++i){
		    a1[i]=rand()%101;
		  }
		  BubSort(a1,N,srav,pers);

		  for(int i=0;i<N;++i){
            a1[i]=rand()%101;
		  }
		  ShakerSort(a1,1,N,srav,pers);
		}
		else if(slu==2){
          for(int i=0;i<N;++i){
		    a1[i]=rand()%101;
          }
		  SortBestCase(a1,N);
		  reverse(a1,N);
          heapSort(a1,N,srav,pers);

          SortBestCase(a1,N);
		  reverse(a1,N);
          start = clock();
		  quickSort(a1,0,N-1,srav,pers);
          end = clock();
          double seconds = (double)(end - start) / CLOCKS_PER_SEC;
          cout << "\nВремя Быстрой сортировки = " << seconds;
          cout<<"\nКоличество: Сравнений: "<<srav<<"  Перестановок: "<<pers;
          srav=0; pers=0;

          SortBestCase(a1,N);
		  reverse(a1,N);
          BubSort(a1,N,srav,pers);

          SortBestCase(a1,N);
		  reverse(a1,N);
          ShakerSort(a1,1,N,srav,pers);
		}
		else if(slu==3){
          for(int i=0;i<N;++i){
		    a1[i]=rand()%101;
          }
          SortBestCase(a1,N);
          heapSort(a1,N,srav,pers);

          start = clock();
		  quickSort(a1,0,N-1,srav,pers);
          end = clock();
          double seconds = (double)(end - start) / CLOCKS_PER_SEC;
          cout << "\nВремя Быстрой сортировки = " << seconds;
          cout<<"\nКоличество: Сравнений: "<<srav<<"  Перестановок: "<<pers;
          srav=0; pers=0;

          BubSort(a1,N,srav,pers);

          ShakerSort(a1,1,N,srav,pers);
		}
		delete []a1;
		break;
    }
	}

	cout << "\nПовторить?\n1. Да\n2. Нет";
	cin >> a;
	if(a==1)
		goto label1;
	system("pause");
return 0;
}

/*Найти медиану графа, то есть найти такую вершину графа, 
суммарное расстояние от которой до всех остальных вершин является наименьшим.*/
#include <iostream>


using namespace std;

const int maxPath = 100000;


bool CheckTop(int **Matr, int Num, int n, int & sum) {
	//реализация алгоритма Дейкстры
	/*Создание матрицы коротких путей*/
	int *ShortPath = new int[n];
	/*Создание матрицы посещенных вершин*/
	int *Visited = new int[n];
	//заполняем массивы посещенных вершин и коротких путей
	int i;
	sum = 0;
	for (i = 0; i < n; i++) {
		ShortPath[i] = maxPath;
		Visited[i] = 0; //0 - не посещена, 1 - посещена
	}
	ShortPath[Num] = 0; //короткий путь до исходной вершины - 0
	
	int top = Num; //top - текущая вершина

	do
	{
		i = 0;
		for (; i < n; i++) {//если новая вершина не текущая и не была посещена и расстояние до неё из исходной короче, чем было
			if (i != top && Visited[i] == 0 && Matr[i][top]>0 && ShortPath[top] + Matr[i][top] < ShortPath[i]) {
				ShortPath[i] = ShortPath[top] + Matr[i][top];//обновляем длину пути к вершине i
			}
		}
		Visited[top] = 1; //текущая вершина проверена

		int min = maxPath;//ближайщая вершина
		top = -1; //вершина, которая будет выбрана текущей для следующего шага
		for (i = 0; i < n; i++) { //ищем непроверенную вершину с самым коротким путем
			if (Visited[i] == 0 && ShortPath[i] < min) {
				min = ShortPath[i];
				top = i;
			}
		}

	} while (top != -1); //все вершины проверены
	


	i = 0;
	while (i < n && ShortPath[i] < maxPath) {
		sum += ShortPath[i];
		i++;
	}
		
	/*Удаление матрицы путей*/
	delete[] ShortPath;
	delete[] Visited;

	if (i == n) return true;
	//else
	return false;
	

}

int main() {

	setlocale(LC_ALL, "Russian");
	/*Создание динамической матрицы*/
	int n;
	cout << "Введите количество вершин" << endl;
	cin >> n;
	int **Graf = new int*[n];
	for (int i = 0; i < n; i++) {
		Graf[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		Graf[i][i] = 0;
		
	}

	/*Ввод графа в матрицу*/
	cout << "Введите веса ребeр между вершинами:" << endl;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int a;
			cout <<  i+1 << " и " << j+1 << ", если ребра нет, введите 0." << endl;
			cin >> a;
			Graf[i][j] = a;
			Graf[j][i] = a;
		}
	}
	//вывод графа
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Graf[i][j] << " ";
		}
		cout << endl;
	}

	//проверяем каждую вершину и если от нее есть пути во все остальные, сравниваем сумму этих путей с минимумом, запоминая вершину
	int sum = 0, minsum = maxPath;
	int SearchTop = -1;
	for (int i = 0; i < n; i++) {
		if (CheckTop(Graf, i, n, sum) &&  (sum < minsum)) {
			SearchTop = i;
			minsum = sum;
		}
	}

	if (SearchTop == -1) {
		cout << "В графе нет медианы" << endl;
	}
	else
		cout << "Медиана графа - вершина номер "<< SearchTop+1 << ", сумма - "<< minsum <<endl;


	/*Удаление матрицы из памяти*/
	for (int i = 0; i < n; i++) {
		delete[] Graf[i];
	}
	

	/*
	5
	3
	5
	0
	7
	2
	0
	0
	2
	6
	4
	
		
	*/



	return 0;
}